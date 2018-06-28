import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static void main (String [] args) throws IOException {
      //  File in = new File ("in.txt");
        Scanner sc = new Scanner(System.in);

      //  File out = new File ("out.txt");
      //  PrintWriter writer = new PrintWriter (out);

        while (true)
        {
            BigInteger n = sc.nextBigInteger();

            if (n.intValue() == 0)
            break;
            
            BigInteger d = n.mod(BigInteger.valueOf(10));
          //  System.out.println(d);

            BigInteger temp = d.multiply( BigInteger.valueOf(5));
            temp = temp.negate();
            n = n.divide(BigInteger.valueOf(10));
            boolean ans = false;
            if ( (n.add (temp)).mod (BigInteger.valueOf(17)).intValue() == 0 )
            ans = true;
            else
            ans = false;

            if (ans)
            System.out.println("1");
            else
            System.out.println("0");
    
        }
       // writer.close();
    }
}