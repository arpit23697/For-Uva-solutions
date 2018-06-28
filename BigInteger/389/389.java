import java.util.*;
import java.io.*;
import java.math.*;


class Main {
    public static void main (String [] args) throws IOException {
      // File in = new File ("in.txt");
        Scanner sc = new Scanner (System.in);

       // File out = new File ("out.txt");
      //  PrintWriter writer = new PrintWriter(out);

        while (sc.hasNext())
        {
            String num = sc.next();
           // writer.println(num);

            int b1 , b2;
            b1 = sc.nextInt();
            b2 = sc.nextInt();

            BigInteger x = new BigInteger(num , b1 );
            String str2 = x.toString(b2);
            if (str2.length() > 7)
            System.out.println("  ERROR");
            else
            System.out.printf("%7s\n" , str2.toUpperCase());
        }
        //writer.close();
    }
}