import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        final int alliritations = 20;
        double denominator  =1.0;
        double term = 1.0;
        double estimatepi = 0.0;
        int iterations = 0;
//        System.out.println("n\t\tdenominator\tterm\t\testimatedPi");
        System.out.println("==\t\t===========\t====\t\t===========");

        while(term > 0.00000001 ){
//            if(iterations <= alliritations){
//                System.out.println(iterations + "\t\t" + denominator + "\t\t" + term + "\t\t" + estimatepi);
//            }
            estimatepi += term;
            denominator += 2.0;
            iterations++;
            if (iterations % 2 == 0){
                term =  4.0 / denominator;
            }
            else{
                term = -4.0 / denominator;

            }

        }


        System.out.println("The number of iterations was: " + iterations);
        System.out.println("The estimated pi is: " + estimatepi);
        System.out.println("Math.PI: " + Math.PI);
}


}