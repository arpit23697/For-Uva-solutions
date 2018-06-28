import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.Integer;


class Main {
    public static void main (String [] args) throws IOException {
        //File in = new File ("in.txt");
        Scanner sc = new Scanner (System.in);

    //  File out = new File ("out.txt");
      // PrintWriter writer = new PrintWriter(out);

        while (true)
        {
            BigInteger p , a;
            p = sc.nextBigInteger();
            a = sc.nextBigInteger();

            if (p.compareTo(BigInteger.ZERO) == 0 && a.compareTo(BigInteger.ZERO) == 0)
            break;

            boolean ans = true;
            if (p.isProbablePrime(10))
            {
                System.out.println("no");
                continue;
            }

            if ((a.modPow (p , p)).compareTo(a) == 0)
            System.out.println("yes");
            else
            System.out.println("no");

        }
       // writer.close();
    }
}