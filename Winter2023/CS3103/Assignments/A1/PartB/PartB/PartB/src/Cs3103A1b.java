import java.io.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Scanner;

public class Cs3103A1b {
    public static void main(String[] args) {
        String protocol, domainName, path, portNum;
        Scanner scanner = new Scanner(System.in);

        System.out.println("Write the protocol you want to use?");
        protocol = scanner.nextLine();
        if(protocol.isEmpty())
            protocol = "https";

        System.out.println("Write the domain name");
        domainName = scanner.nextLine();
        if(domainName.isEmpty())
            domainName = "cs3103.cs.unb.ca";

        System.out.println("Write the path");
        path = scanner.nextLine();
        if (path.isEmpty())
            path = "/mmoustaf/index.html";

        System.out.println("Write the port number");
        portNum = scanner.nextLine();
        if(portNum.isEmpty())
            portNum = "443";


        try {
            URL url = new URL(protocol,domainName,Integer.parseInt(portNum), path);
            Scanner pathScanner = new Scanner(path);
            pathScanner.useDelimiter("/");
            String fileName = "";
            while(pathScanner.hasNext()){
                if(!pathScanner.hasNext("/"))
                {
                    fileName = pathScanner.next();
                }
            }
            File file = new File(fileName);
            if (file.createNewFile()){
                System.out.println("File created: " + file.getName() + "\n");
            }else{
                System.out.println("File was not created as it already exists");
            }
            FileOutputStream fos = new FileOutputStream(fileName);

            BufferedReader in = new BufferedReader(
                    new InputStreamReader(url.openStream()));

            String inputLine;
            while ((inputLine = in.readLine()) != null){
                System.out.println(inputLine);
                fos.write(inputLine.getBytes());
            }
            fos.close();
            in.close();


        } catch (MalformedURLException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }



    }
}