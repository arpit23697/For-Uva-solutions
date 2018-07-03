import java.util.*;
import java.math.*;
import java.io.*;

class Main {
    public static void main (String [] args) throws IOException {
       // File in = new File("in.txt");
        Scanner sc = new Scanner (System.in);

      //  File out = new File ("out.txt");
      //  PrintWriter writer = new PrintWriter (out);

        int test = sc.nextInt();
        BigInteger [] ans = new BigInteger[45];
        ans[0] = BigInteger.valueOf(1);
        ans[1] = BigInteger.valueOf(5);
        ans[2] = BigInteger.valueOf(11);

        for (int i= 3 ; i < 45 ; i++)
        ans[i] = ans[i-1].add(BigInteger.valueOf(4).multiply(ans[i-2])).add(BigInteger.valueOf(2).multiply(ans[i-3]));

        
        while(test > 0)
        {   
            test--;
            int n = sc.nextInt();   
            System.out.println(ans[n-1]);       

        }
       // writer.close();
    }
}