import java.util.*;
import java.math.*;
import java.io.*;

class Main {
    public static void main (String [] args) throws IOException {
      //  File in = new File("in.txt");
        Scanner sc = new Scanner (System.in);

       // File out = new File ("out.txt");
       // PrintWriter writer = new PrintWriter (out);


        while(sc.hasNext())
        {   
            int n = sc.nextInt();
            int k = sc.nextInt();

            BigInteger ans = BigInteger.valueOf(1);
            for (int i = 0 ; i < k ; i++ )
                ans = ans.multiply(BigInteger.valueOf(n-i)).divide(BigInteger.valueOf(i+1));
            
            System.out.println(ans.toString().length());

        }
        //writer.close();
    }
}