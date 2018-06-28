import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.Integer;


class Main {
    public static void main (String [] args) throws IOException {
      //  File in = new File ("in.txt");
        Scanner sc = new Scanner (System.in);

      //  File out = new File ("out.txt");
      // PrintWriter writer = new PrintWriter(out);

        while (sc.hasNext())
        {
            int n;
            n = sc.nextInt();
            BigInteger x = BigInteger.valueOf(n);
            String rev = new StringBuffer (x.toString()).reverse().toString();
            int RN = Integer.parseInt(rev);

            BigInteger y = BigInteger.valueOf(RN);
            boolean prime = x.isProbablePrime(10);
            boolean revPrime = y.isProbablePrime(10);
           // writer.print(prime + " " + revPrime);
            if (prime && revPrime && RN != n)
            System.out.println(n + " is emirp.");
            else if (prime)
            System.out.println(n + " is prime.");
            else 
            System.out.println(n + " is not prime.");
        }
       // writer.close();
    }
}