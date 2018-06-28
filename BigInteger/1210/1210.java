import java.util.*;
import java.io.*;
import java.math.*;


class Main {
    public static void main (String [] args) throws IOException {
     //   File in = new File ("in.txt");
        Scanner sc = new Scanner (System.in);

       // File out = new File ("out.txt");
       // PrintWriter writer = new PrintWriter(out);

        while (true)
        {
           int n = sc.nextInt();
           if (n == 0)
           break;

            int prime[] = new int[1500];
            int len = 0;

           if (n < 2)
           {
               System.out.println("0");
               continue;
           } 
            prime[0] = 2;
            len++;
            for (int i = 3 ; i <= n ; i+=2)
            {
                if (BigInteger.valueOf(i).isProbablePrime(10))
                {
                    
                    prime[len] = i;
                    len++;
           //         writer.println("len" + len);
                }
            }
         //    writer.println("len + final " + len);
          /*  for (int i=0 ; i < len ; i++)
            writer.print(prime[i] + " ");
            writer.println();
           */ int ans =0;
            for (int i=0 ; i < len ; i++)
            {
                int sum = 0;
                for (int j = i ; j < len ; j++)
                {
                    sum = sum + prime[j];
                    if (sum == n)
                    {
                       // writer.println(sum);
                        ans++;
                        break;
                    }
                }
            }
            System.out.println(ans);
            //writer.println(ans);
        }
       // writer.close();
    }
}