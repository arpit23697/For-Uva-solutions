import java.util.*;
import java.math.*;
import java.io.*;

class Main {
    public static void main (String [] args) throws IOException {
       // File in = new File("in.txt");
        Scanner sc = new Scanner (System.in);

       // File out = new File ("out.txt");
      //  PrintWriter writer = new PrintWriter (out);


        int test= sc.nextInt();
        int cases = 0;
        while(test > 0)
        {   
            cases++;
            test--;
           
            String str = sc.next();
            String x = "";
            int temp = -1;
            for (int i= 1 ; ; i++)
            {
                if (str.charAt(i) == '+')
                {
                    temp = i;
                    break;
                }
                else
                    x = x + str.charAt(i);
                
            }
            String y = "";
            for (int i= temp + 1 ; ; i++)
            {
                if (str.charAt(i) == ')')
                {
                    temp = i;
                    break;
                }
                else
                    y = y + str.charAt(i);
                
            }
            String num = "";
            int len = str.length();
            for (int i = temp+2 ; i < len; i++)
                num = num + str.charAt(i);
            
            int n = Integer.parseInt(num);
            String ans = "";

            BigInteger coef = BigInteger.valueOf(1);
            int powerOfX = n;
            int powerOfY = 0;

            ans = ans + x;
            if (powerOfX != 1)
            ans = ans + '^' + Integer.toString(powerOfX);
            
            for (int i =0 ; i< n ; i++)
            {
                coef = coef.multiply(BigInteger.valueOf(n-i)).divide(BigInteger.valueOf(i+1));
                powerOfX--;
                powerOfY++;
                ans = ans + '+';
                if (coef.compareTo(BigInteger.valueOf(1))  != 0)
                ans = ans + coef.toString();

                if (powerOfX != 0)
                {
                    ans = ans + '*';
                    if (powerOfX == 1)
                    ans = ans + x;
                    else
                    ans = ans + x + '^' + Integer.toString(powerOfX);
                }
                if (powerOfY != 0)
                {
                    if (powerOfX != 0)
                    ans = ans + '*';
                    if (powerOfY == 1)
                    ans = ans + y;
                    else
                    ans = ans + y + '^' + Integer.toString(powerOfY);
                }
            }    
            System.out.println("Case " + cases + ": " + ans);
        }
       // writer.close();
    }
}