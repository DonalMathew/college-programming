import java.util.*;
public class Secondsmallest{
    public static void main(String args []){
        Scanner s = new Scanner(System.in);
        int n,temp;
        System.out.print("enter the number of elements of array :");
        n = s.nextInt();
        int a[] = new int[n];
        for(int i=0; i<n ;i++){
            System.out.print("enter the"+(i+1)+"th element of the array : ");
            a[i]=s.nextInt();
        }
         for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1; j++){
                if (a[j] > a[j + 1]) {
                    // swap arr[j+1] and arr[j]
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
         }
    System.out.print("second smallest element is :"+a[1]);
    }
}