import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    public static void main (String [] args){
      //  File in = new File ("in.txt");
        Scanner sc = new Scanner(System.in);

      //  File out = new File("out.txt");
      //  PrintWriter writer = new PrintWriter (out);

        int test = sc.nextInt();
        while (test > 0)
        {
            test--;
            BigInteger first = sc.nextBigInteger();
            BigInteger second = sc.nextBigInteger();

           // writer.println(first + " " + second);
            String R = new StringBuffer(first.toString()).reverse().toString();
            BigInteger fR = new BigInteger(R);

            String R2 = new StringBuffer (second.toString()).reverse().toString();
            BigInteger sR = new BigInteger(R2);

           // writer.println(fR + " " + sR);
            BigInteger ans = fR.add(sR);
            String R3 = new StringBuffer(ans.toString()).reverse().toString();
            System.out.println(new BigInteger(R3));
        }
        //writer.close();
    }
}