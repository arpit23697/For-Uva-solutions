import java.util.*;
import java.io.*;
import java.math.*;


class Main {
    public static void main (String [] args) throws IOException {
     //   File in = new File ("in.txt");
        Scanner sc = new Scanner (System.in);

      //  File out = new File ("out.txt");
     //   PrintWriter writer = new PrintWriter(out);

        while (true)
        {
           int b = sc.nextInt();
           if (b == 0)
           break;

           String p = sc.next();
           String m = sc.next();

           BigInteger x = new BigInteger(p , b);
           BigInteger y = new BigInteger(m , b);

           BigInteger ans = x.mod(y);
           System.out.println(ans.toString(b));
        }
       // writer.close();
    }
}