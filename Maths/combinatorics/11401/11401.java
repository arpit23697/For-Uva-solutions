import java.util.*;
import java.math.*;
import java.io.*;

class Main {
    public static void main (String [] args) throws IOException {
    //   File in = new File("in.txt");
        Scanner sc = new Scanner(System.in);

       // File out = new File ("out.txt");
       // PrintWriter writer = new PrintWriter (out);

        while(true)
        {  
            int n2 = sc.nextInt();   
            if (n2 == 0)
            break;
            
            n2 = n2-2;
            BigInteger n = BigInteger.valueOf(n2);
            BigInteger ans = BigInteger.valueOf(4).multiply(n.pow(3));
            ans = ans.add(BigInteger.valueOf(6).multiply(n.pow(2)));
            ans = ans.add(BigInteger.valueOf(-4).multiply(n));
            if (n.mod(BigInteger.valueOf(2)).compareTo(BigInteger.valueOf(0)) == 0)
            ans = ans.add(BigInteger.valueOf(3));
            else
            ans = ans.add(BigInteger.valueOf(-3));

            ans = ans.divide(BigInteger.valueOf(48));
           System.out.println(ans);

        }
       // writer.close();
    }
}