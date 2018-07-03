import java.util.*;
import java.math.*;
import java.io.*;

class Main {
    public static void main (String [] args) throws IOException {
    //    File in = new File("in.txt");
        Scanner sc = new Scanner (System.in);

     //   File out = new File ("out.txt");
     //   PrintWriter writer = new PrintWriter (out);


        int test= sc.nextInt();
        while(test > 0)
        {   
            test--;
            int n = sc.nextInt();
            int k = sc.nextInt();

            int sum = 0;
            int temp;
            for (int i = 0 ; i < k ; i++)
            {
                temp = sc.nextInt();
                sum += temp;
            }

            int x = k+1;
            int y = n - sum - k + 1;
            if (y < 0)
            System.out.println("0");
            else
            {
                int first = x + y - 1;
                int second = x - 1;
                
                BigInteger ans = BigInteger.valueOf(1);
                
                for (int i = 0 ; i < second ; i++)
                    ans = ans.multiply(BigInteger.valueOf(first-i)).divide(BigInteger.valueOf(i+1));
                
                
                System.out.println(ans);
            }
            
        }
       // writer.close();
    }
}