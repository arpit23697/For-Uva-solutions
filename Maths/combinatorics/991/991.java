import java.util.*;
import java.math.*;
import java.io.*;

class Main {
    public static void main (String [] args) throws IOException {
    //    File in = new File("in.txt");
        Scanner sc = new Scanner (System.in);

     //   File out = new File ("out.txt");
     //   PrintWriter writer = new PrintWriter (out);

        while(sc.hasNext())
        {   
            int n = sc.nextInt();
            BigInteger ans = BigInteger.valueOf(1);

            for (int i = 0 ; i < n ; i++)
            {
               // System.out.println(ans);
                ans = ans.multiply (BigInteger.valueOf(2*i + 2)).multiply(BigInteger.valueOf(2*i + 1)).divide(BigInteger.valueOf(i+2)).divide(BigInteger.valueOf(i+1)); 
            }
            System.out.println(ans);
            if (sc.hasNext())
            System.out.println();
        }
       // writer.close();
    }
}