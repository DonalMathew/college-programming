import java.util.*;
public class Transpose{
    public static void main(String args []){
        //
        Scanner s = new Scanner(System.in);
        //
        int n,m;
        System.out.print("enter the row of the matrix :");
        n = s.nextInt();
        System.out.print("enter the column of the matrix :");
        m = s.nextInt();
        int m1[][] = new int[n][m];
        //
        System.out.print("enter the elements of the matrix :");
        for(int i = 0; i<n; i++){
            for(int j = 0;j<m;j++){
                m1[i][j] = s.nextInt();
            }
        }
        System.out.print("transpose of the matrix is : \n");
        for(int i = 0; i<n; i++){
            for(int j = 0;j<m;j++){
               System.out.print(m1[j][i]+"\t");
            }
            System.out.println();
        }
        
    }
}