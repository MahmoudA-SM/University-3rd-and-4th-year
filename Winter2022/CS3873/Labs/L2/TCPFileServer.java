
import java.io.*;
import java.net.*;

class TCPFileServer {
  public static void main(String args[]) throws Exception {

    String capitalizedSentence;
    ServerSocket welcomeSocket = new ServerSocket(6789);
    System.out.println ("Waiting for connection.....");
    Socket connectionSocket = welcomeSocket.accept();
    BufferedReader inFromClient = new BufferedReader(
    new InputStreamReader(connectionSocket.getInputStream()));
    DataOutputStream outToClient = new DataOutputStream(
    connectionSocket.getOutputStream());
    String clientSentence = inFromClient.readLine();

    while (clientSentence != null) {

      System.out.println("From client at " + connectionSocket.getInetAddress()
      + ": " + clientSentence);
      // System.out.println(clientSentence);
      if (clientSentence.equalsIgnoreCase("Done")){
        outToClient.writeBytes("Bye"+'\n');
      }
      else{
        capitalizedSentence = clientSentence.toUpperCase() + '\n';
        outToClient.writeBytes(capitalizedSentence);
      }


      clientSentence = inFromClient.readLine();
    }
  }
}
