import java.util.*;
import java.math.*;
import java.io.*;

class Main {
    public static void main (String [] args) throws IOException {
      //  File in = new File("in.txt");
        Scanner sc = new Scanner (System.in);

      //  File out = new File ("out.txt");
      //  PrintWriter writer = new PrintWriter (out);

        BigInteger fib[] = new BigInteger[105];
        fib[0] = BigInteger.valueOf(1);
        fib[1] = BigInteger.valueOf(2);
        for (int i = 2; i < 105 ; i++)
        fib[i] = fib[i-1].add(fib[i-2]);


       // for (int i= 0 ; i < 100 ; i++)
       // writer.println(fib[i]);
        while(true)
        {
            String x , y;
            x = sc.next();
            y = sc.next();

            BigInteger first = BigInteger.ZERO;
            BigInteger second = BigInteger.ZERO;
            int len = x.length();
            for (int i = len-1 ; i>=0 ; i--)
                first = fib[len - 1 - i].multiply(BigInteger.valueOf(x.charAt(i) - '0')).add(first);
            
            len = y.length();
            for (int i = len - 1 ; i>= 0 ; i--)
                second = fib[len - 1 - i].multiply(BigInteger.valueOf(y.charAt(i) - '0' )).add(second);


         //   System.out.println(first);
         //   System.out.println(second);
            BigInteger ans = first.add(second);
            int start = -1;
            String str = "";

          //  System.out.println(ans);

            for (int i = 104 ; i>= 0 ; i--)
            if (ans.compareTo(fib[i]) >= 0 )
            {
                start = i;
                break;
            }

            

            //System.out.println("====" + start);

            BigInteger temp;
            for (int i = start ; i >= 0 ; i--)
            {
            //    System.out.println(ans);
                if (ans.compareTo(fib[i]) >= 0)
                {   
                    str = str + '1';
                    temp = fib[i].negate();
                    ans = ans.add(temp);
                }
                else
                {
                    str = str + '0';
                }
            }
            if (start == -1)
            System.out.println("0");
            else
            System.out.println(str);
            if (sc.hasNext())
            System.out.println();
            else
            break;
        }
       // writer.close();
    }
}