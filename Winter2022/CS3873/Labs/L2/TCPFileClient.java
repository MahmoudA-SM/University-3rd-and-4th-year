import java.io.*;
import java.net.*;
import java.util.Scanner;
class TCPFileClient{
  public static void main(String[] args) throws Exception {
    String sentence;
    String modifiedSentence;
    File file = new File("PoemShakespeare.txt");
    Scanner inFromUser = new Scanner (file);
    Socket clientSocket = new Socket(args[0], 6789);
    DataOutputStream outToServer = new DataOutputStream(
    clientSocket.getOutputStream());
    BufferedReader inFromServer = new BufferedReader(new InputStreamReader(
    clientSocket.getInputStream()));
    int x = 0;
    long startTime = 0, endTime;
    while(inFromUser.hasNextLine()){
      sentence = inFromUser.nextLine();
      if (x == 0){
        startTime = System.currentTimeMillis();
        x++;
      }

      outToServer.writeBytes(sentence + '\n');

      modifiedSentence = inFromServer.readLine();
      System.out.println("FROM SERVER: " + modifiedSentence);
    }
    outToServer.writeBytes("Done" + '\n');
    modifiedSentence = inFromServer.readLine();
    System.out.println("FROM SERVER: " + modifiedSentence);

    if(modifiedSentence.equalsIgnoreCase("Bye")){
      endTime = System.currentTimeMillis();
      clientSocket.close();
      System.out.println("Number of data sent in bytes: " + outToServer.size());
      System.out.println("Total time: " + (endTime - startTime) + "ms");
    }


  }
}
