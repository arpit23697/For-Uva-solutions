    import java.util.*;
    import java.io.*;
    import java.math.*;

    class Main {
        public static void main (String [] args) 
        {
        //   File in = new File ("in.txt");
            Scanner sc = new Scanner(System.in);

        // File out = new File("out.txt");
        //  PrintWriter writer = new PrintWriter ("out.txt");
            while (sc.hasNext())
            {
                int n = sc.nextInt();
                BigInteger a = sc.nextBigInteger();

                BigInteger ans = BigInteger.ZERO;
                for (int i= 1 ; i <= n ; i++)
                {
                //    writer.println(ans);
                    ans = ans.add (BigInteger.valueOf(i).multiply(a.pow(i)));
                }
                System.out.println(ans);
            }
        // writer.close();
        }
    }