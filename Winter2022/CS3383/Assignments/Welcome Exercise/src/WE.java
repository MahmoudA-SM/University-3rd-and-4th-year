public class WE{

    static int largest = 0;
    static int secondLargest = 0;
    public static int recursive(int[] array,int l){

        if (l >= array.length){
            return 0;
        }

        if (largest < secondLargest){
            largest = secondLargest;
        }
        if (array[l] > largest){
            largest = array[l];
        }


        recursive(array,l+1);
        if (secondLargest < array[l] && array[l] < largest){
            secondLargest = array[l];
        }
        return secondLargest;
    }

    public static void iterative(int[] array){
        int secondLargest = array[0];
        int largest = array[1];
        for(int i = 0; i < array.length; i++){
            if (array[i] > largest){
                largest = array[i];
            }
            if(largest < secondLargest){
                largest = secondLargest;
            }

        }
        for (int i = 0; i < array.length; i++){
            if(secondLargest<array[i] && array[i]<largest){
                secondLargest = array[i];
            }
        }
        System.out.println("Iterative Second Largest: " + secondLargest);
    }

    public static void main(String[] args) {
        int[] array = {3,1,6,5,8,-20,9,12,61,91,9};
        System.out.println("Recursive Second Largest: " + recursive(array,0));
        iterative(array);

    }
}