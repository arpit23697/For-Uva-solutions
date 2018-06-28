import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.Integer;


class Main {
    public static void main (String [] args) throws IOException {
     //   File in = new File ("in.txt");
        Scanner sc = new Scanner (System.in);

  //  File out = new File ("out.txt");
    // PrintWriter writer = new PrintWriter(out);

        int test = sc.nextInt();


        while (test > 0)
        {
            test--;
            BigInteger x , y;
            String str;
            x = sc.nextBigInteger();
            str = sc.next();
            y = sc.nextBigInteger();

            BigInteger gcdValue = x.gcd(y);
            System.out.println(x.divide(gcdValue) + " " +str+ " " + y.divide(gcdValue));
        }
       
      //  writer.close();
    }
}