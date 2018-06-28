import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main (String [] args)
    {
     //   File in = new File ("in.txt");
        Scanner sc = new Scanner(System.in);

       // File output = new File ("out.txt");
       // PrintWriter writer = new PrintWriter(output);

        int caseNo = 0;
        while (true)
        {
            caseNo++;
            //System.out.println();
            int n = sc.nextInt();
            int f = sc.nextInt();

            if (n ==0 && f == 0)
            break;

            BigInteger sum = BigInteger.ZERO;
            for (int i= 0 ; i < n ; i++)
            {
                BigInteger V = sc.nextBigInteger();
                sum = sum.add(V);
            }
           // System.out.println(sum);
            System.out.println("Bill #" + caseNo + " costs " + sum + ": each friend should pay " + sum.divide(BigInteger.valueOf(f)));
            System.out.println();
            
        }
       // writer.close();
    }
}