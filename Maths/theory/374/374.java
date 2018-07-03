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
            BigInteger n = sc.nextBigInteger();
            BigInteger p = sc.nextBigInteger();
            BigInteger m = sc.nextBigInteger();
            System.out.println(n.modPow(p , m));
        }
       // writer.close();
    }
}