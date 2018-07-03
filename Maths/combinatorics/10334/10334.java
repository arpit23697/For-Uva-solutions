import java.util.*;
import java.math.*;
import java.io.*;

class Main {
    public static void main (String [] args) throws IOException {
     //   File in = new File("in.txt");
        Scanner sc = new Scanner (System.in);

     //   File out = new File ("out.txt");
     //   PrintWriter writer = new PrintWriter (out);

        BigInteger fib[] = new BigInteger[1005];
        fib[0] = BigInteger.valueOf(1);
        fib[1] = BigInteger.valueOf(2);
        for (int i = 2; i < 1005 ; i++)
        fib[i] = fib[i-1].add(fib[i-2]);


       // for (int i= 0 ; i < 100 ; i++)
       // writer.println(fib[i]);
        while(sc.hasNext())
        {   
           int n = sc.nextInt();
           System.out.println(fib[n]);
        }
       // writer.close();
    }
}