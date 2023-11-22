#define _GNU_SOURCE
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "console.h"
#include "example.h"

#define GAME_ROWS 24
#define GAME_COLS 80
pthread_mutexattr_t attributes;
pthread_mutex_t mutex;

/**** DIMENSIONS MUST MATCH the ROWS/COLS */
char *GAME_BOARD[] = {
    "                   Score:          Lives:",
    "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-centipiede!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"",
    "",
    "",
    "",
    "",
    "",
    "",
    ""};

#define ENEMY_HEAD_Height 2
#define ENEMY_HEAD_ANIM_TILES 4
char *ENEMY_HEAD[ENEMY_HEAD_ANIM_TILES][ENEMY_HEAD_Height] =
    {
        {"@",
         "="},
        {"@",
         "="},
        {"@",
         "="},
        {"-",
         "="}};

#define ENEMY_HEIGHT 2
#define ENEMY_BODY_ANIM_TILES 4
char *ENEMY_BODY[ENEMY_BODY_ANIM_TILES][ENEMY_HEIGHT] =
    {
        {"|",
         ";"},
        {"|",
         ";"},
        {"|",
         ";"},
        {"^",
         ";"}};

#define PLAYER_HEIGHT 3
#define PLAYER_BODY_ANIM_TILES 4
char *PLAYER_SHIP[PLAYER_BODY_ANIM_TILES][PLAYER_HEIGHT] =
    {
        {"[0]",
         "==-",
         "/|\\"},

        {"[@]",
         "=-=",
         "/|\\"},

        {"[0]",
         "-==",
         "/|\\"},

        {"[@]",
         "===",
         "/|\\"},
};

int pos[] = {19, 40};
int current_tile = 0;

void exampleRun()
{
  if (consoleInit(GAME_ROWS, GAME_COLS, GAME_BOARD)) // start the game (maybe need to do this elsewhere...)
  {
    pthread_mutexattr_init(&attributes);
    pthread_mutexattr_settype(&attributes, PTHREAD_MUTEX_NORMAL);
    pthread_mutex_init(&mutex, &attributes);
    // only run one example at once (comment others out).
    // these examples should be removed in your final submission!
    pthread_t player_animation, player_movement;
    int rc;

    moveEnemyExample(2, 79);
    // multipleEnemyExample();

    rc = pthread_create(&player_animation, NULL, playerAnimationExample, (void *)pos);
    if (rc)
    {
      printf("ERROR-return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
    rc = pthread_create(&player_movement, NULL, playerControlExample, NULL);
    if (rc)
    {
      printf("ERROR-return code from pthread_create() is %d\n", rc);
      exit(-1);
    }

    rc = pthread_join(player_animation, NULL);
    rc = pthread_join(player_movement, NULL);

    pthread_mutex_destroy(&mutex);

    pthread_exit(NULL);

    finalKeypress(); /* wait for final key before killing curses and game */
  }
  consoleFinish();
}

// no threading...just an example of drawing to the console
// and an example of how animation works...just drawing a picture one at a time...fast!
void moveEnemyExample(int row, int col)
{
  for (int i = 0; i < ENEMY_BODY_ANIM_TILES; i++) // loop over the whole enemy animation once
                                                  // this "animation" is just the body changing appearance (changing numbers)
  {
    pthread_mutex_lock(&mutex);
    char **tile = ENEMY_BODY[i];

    consoleClearImage(row, col - i, ENEMY_HEIGHT, strlen(tile[0]) + i); // clear the last drawing (why is this necessary?)
    updateEnemy(row, col, i);
    consoleRefresh(); // reset the state of the console drawing tool
    usleep(1000000);  // give up our turn on the CPU
    pthread_mutex_unlock(&mutex);
  }

  pthread_exit(NULL);
}

void updateEnemy(int row, int col, int current)
{
  for (int i = 0; i <= current; i++)
  {
    char **tile = ENEMY_BODY[i];
    char **headTile = ENEMY_HEAD[i];
    
    if (i % 4 == 0)
      consoleDrawImage(row, col - current + i - 1, headTile, ENEMY_HEAD_Height);
    consoleDrawImage(row, col - current + i, tile, ENEMY_HEIGHT);
  }
}

void *playerAnimationExample(void *v)
{
  int *pos;
  int row, col;
  char **tile;
  while (current_tile < PLAYER_BODY_ANIM_TILES)
  {
    // pthread_mutex_lock(&mutex);
    pos = (int *)v;
    row = pos[0];
    col = pos[1];
    tile = PLAYER_SHIP[current_tile];

    consoleClearImage(row, col, PLAYER_HEIGHT, strlen(tile[0]));
    consoleDrawImage(row, col, tile, PLAYER_HEIGHT);
    consoleRefresh();
    usleep(250000);

    if (current_tile == PLAYER_BODY_ANIM_TILES - 1)
    {
      current_tile = 0;
    }
    else
    {
      current_tile++;
    }
    // pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

void *playerControlExample()
{
  fd_set set; /* what to check for our select call */
  bool gameRunning = true;
  int row = 19;
  int col = 40;
  char **tile;

  while (gameRunning)
  {
    /* setup select to listen to stdin. necessary as getchar
      is blocking and cannot be easily unblocked, e.g.,
                  to end the game*/
    /* re-set each time as it can get overwritten */
    // essentially, wait for a key, or a timeout
    // read man page for pselect to understand all of this!
    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);
    struct timespec timeout = getTimeout(1); /* duration of one tick */
    int ret = pselect(FD_SETSIZE, &set, NULL, NULL, &timeout, NULL);

    /* check if we timed out, or, event happened.
      also, game may have ended while we waited */
    if (gameRunning && ret >= 1)
    {
      char c = getchar();
      // pthread_mutex_lock(&mutex);

      // this move code is too simple for when we get to threads...
      // there's also no error checking
      // we'll have to add in some protection...what are the critical resources here?
      tile = PLAYER_SHIP[current_tile];
      consoleClearImage(row, col, PLAYER_HEIGHT, strlen(tile[0])); // clear the last drawing (why is this necessary? And why here?)
      if (c == MOVE_LEFT && col > 0)
      {
        col -= 1;
      }
      else if (c == MOVE_RIGHT && col < 77)
      {
        col += 1;
      }
      else if (c == MOVE_DOWN && row < 21)
      {
        row += 1;
      }
      else if (c == MOVE_UP && row > 17)
      {
        row -= 1;
      }
      else if (c == QUIT)
      {
        gameRunning = false;
      }

      // NOT THREADED
      // just draw player...using enemy from earlier
      consoleDrawImage(row, col, tile, PLAYER_HEIGHT); // draw the enemy at 10,10 but move them along once per animation image
      consoleRefresh();                                // reset the state of the console drawing tool

      pos[0] = row;
      pos[1] = col;
      // pthread_mutex_unlock(&mutex);
    } /* end select bypass */

  } /* game loop*/
  pthread_exit(NULL);
}

void *moveEnemyExampleT(void *v)
{
  int *pos = (int *)v;
  moveEnemyExample(pos[0], pos[1]);

  return NULL;
}

// this will break!
// why?
// try to fix this using just what we know in class! Then you'll be able to handle the assignment better
void multipleEnemyExample()
{

  pthread_mutexattr_init(&attributes);
  pthread_mutexattr_settype(&attributes, PTHREAD_MUTEX_NORMAL);
  pthread_mutex_init(&mutex, &attributes);

  pthread_t enemy1, enemy2;
  int pos1[] = {2, 79};
  int pos2[] = {2, 79};
  pthread_create(&enemy1, NULL, moveEnemyExampleT, (void *)pos1);
  pthread_create(&enemy2, NULL, moveEnemyExampleT, (void *)pos2);

  pthread_join(enemy1, NULL);
  pthread_join(enemy2, NULL);

  pthread_mutex_destroy(&mutex);

  pthread_exit(NULL);
}
