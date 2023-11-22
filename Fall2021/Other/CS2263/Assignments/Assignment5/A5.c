#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Point2D.h"
#include "Strings.h"
//#include "StringList.h"
#include "Bus.h"
#include "Student.h"


//void disroute(BusRoute* b , int num_routes , Point2D* p  );

// typedef struct busroute
// {
// int numstops;
// Point2D* stop;//[numstops];
// String name;
// }BusRoute;

// typedef struct school
// {
// Point2D initial;
// String name;
// }Student;

int main(int argc, char *argv[])
{
    // FILE * file2 = fopen(argv[2],"r");
    // int num_routes;
    // fscanf(file2, "%d", &num_routes);
    // //printf("%d\n",num_routes );

    // BusRoute b[num_routes];
    // for(int i = 0; i < num_routes; i++)
    // {
        // int ns;
        //   fscanf(file2, "%d", &ns);
        //   numstopsIn(&b[i] , ns);

    //   for(int j =0 ; j < ns ; j++)
//   {
//   double x,y;
//   fscanf(file2, "%lf", &x);
//   fscanf(file2, "%lf", &y);
//   Point2D* p;
//   p = mallocPoint2D();
//   setPoint2D(p ,x ,y);
//   stopIn(&b[i] , p );
//   //free()
//   }
//   String s;
// s= mallocString(50);
// s=getfString(file2 , "\n\0"  );
// nameIN(&b[i] , s);

// Display(&b[i]);
// freeString(s);
// }

// fclose(file2);



// printf(" 3 \n");
// FILE * file;
// file= fopen(argv[1],"r");
// printf(" 4 \n");
//String str= (String)malloc(2000);
// while(!feof(file))
// {
// fgets(str,100,file);
// printf("%s", str );
// }

//fscanf(fin,"%lf")
 // char str[1000];

// String s;
  // s=(String)malloc(6000);


    String ter = "\n\0";
//printf(" 5 \n");
// ter[0] ='\n';
// ter[1] = '\0';
//printf(" 0 \n");

    Student* st;
    double x;
    double y;


 //fgets(str,100,stdin);
 // while(!feof(file))//  fgets(str, 100, stdin))
 // {
    int i;
    for(i = 0 ; i < 10 ; i++)
    {
        // double x;
        // double y;
        printf(" 1 \n");
 
        //fscanf(file , "%lf" , &x );

        scanf("%lf" , &x );
        printf("%lf\n",x );
 
        //fscanf(file , "%lf" , &y);

        scanf("%lf" , &y);

        printf("%lf\n",y );
        // String s2 = (String) malloc(20);
        printf(" 2 \n");
        //= (String)malloc(300000);
        //fgets(s2,100,file);
        //printf("%s",s2);//"\n");
        //strcpy(s,s2);
 
        printf(" 3 \n");
        // pPoint2D p;
        // p = mallocPoint2D();
        // printf(" 4 \n");
        // setPoint2D(p ,x ,y);
        printf(" 5 \n");

        // s2=getfString(file , ter);

        //s2=getString(ter);
        //String s3 =(String) malloc(20);
        char* s2 = (char*) malloc(20);
        if(s2 == (char*)NULL)
        {
            printf(" Problem is here \n");
            return EXIT_SUCCESS;
        }

        gets(s2);
        //gets(s3);

        //s2 = strcat(s2,s3);


        // Student* st;

        printf(" 6 \n");

        st = initialIn(x , y);

        //printf(" 7 \n");

        nameInS(st , s2);

        //printf(" 8 \n");
        DisplayS(st);
        printf(" 9 \n");
        //freeString(s2);
        //freePoint2D(p);
        //free(st);
        printf(" last \n");

    }
    //freeString(s2);
    //fprintf(str, "%s\n", );
 // }

////////////////////////////////////////////////////////

// FILE * file2 = fopen(argv[2],"r");
// int num_stops;
// fscanf(file2, "%d", &num_stops);
// //printf("%d\n",num_stops );

// BusRoute b[num_stops];
// for(int i =0 ; i<num_stops ; i++)
// {
// int ns;
//   fscanf(file2, "%d", &ns);
//   numstopsIn(&b[i] , ns);

//   for(int j =0 ; j < ns ; j++)
//   {
//   double x,y;
//   fscanf(file2, "%lf", &x);
//   fscanf(file2, "%lf", &y);
//   Point2D* p;
//   p = mallocPoint2D();
//   setPoint2D(p ,x ,y);
//   stopIn(&b[i] , p );
//   //free()
//   }
//   String s;
// s= mallocString(50);
// s=getfString(file2 , "\n\0"  );
// nameIN(&b[i] , s);

// Display(&b[i]);
// freeString(s);
// }

// fclose(file2);

////////////////////////////////////////

// FILE * file;
// file= fopen(argv[1],"r");

// while(1==1)
// {
// printf(" here \n");
// double x,y;
// scanf("%lf", &x);
// scanf("%lf", &y);
// // gets();
// // Point2D* p;
// // p = mallocPoint2D();
// // setPoint2D(p ,x ,y);
// Student s;
// printf("what about this \n");
// // Point2D* p;
// // p = mallocPoint2D();
// // setPoint2D(p ,x ,y);
// // initialIn(&s , p);

// printf("Now here\n");
// String st;
// st= mallocString(50);
// //fgets(st ,50)
// st=getString( "\n"  );
// //st=getString( "\n"  );

// // if(st==NULL)
// // {
// // break;
// // }
// nameInS(&s , st);

// DisplayS(&s);


// freeString(st);

// fgets(str,100,file);
// printf("%s", str );
//}



//printf("%d\n",num_stops );
// fscanf(file2, "%d", &num_stops);
// printf("%d\n",num_stops );
// fscanf(file2, "%d", &num_stops);
// printf("%d\n",num_stops );
// fscanf(file2, "%d", &num_stops);
// printf("%d\n",num_stops );
// fscanf(file2, "%d", &num_stops);
// printf("%d\n",num_stops );

// String s;
// s= mallocString(50);
// s=getfString(file2 , "\n"  );
//fgets(s,50 , fscanf(file2 , "%s" , s);
//printf("%s\n", s );
// free(str);

//BusRoute b[num_stops];





return 0;
}