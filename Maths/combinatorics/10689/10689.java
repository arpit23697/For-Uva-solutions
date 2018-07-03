import java.util.*;
import java.math.*;
import java.io.*;

class Main {
    public static void main (String [] args) throws IOException {
      //  File in = new File("in.txt");
        Scanner sc = new Scanner (System.in);

      //  File out = new File ("out.txt");
      //  PrintWriter writer = new PrintWriter (out);

  
        int test = sc.nextInt();
        while(test > 0)
        {   
           test--;
           int a = sc.nextInt();
           int b = sc.nextInt();
           int n = sc.nextInt();
           int m = sc.nextInt();

           int rem;
           int div;
           if (m == 1)
           {
           rem = 60;
           div = 10;
           }
           else if (m == 2) {
           rem = 300;
           div = 100;
           }
           else if (m == 3) {
           rem = 1500;
            div = 1000;
           }
           else { 
           rem = 15000;
           div = 10000;
           }

           int ans;
           int value = n % rem;
           int first = a % div;
           int second = b %div;
            if (value == 0)
            ans = first;
            else if (value == 1)
            ans = second;
            else
            {
                for (int i =2 ; i <= value ; i++)
                {
                    ans = first;
                    first = second;
                    second = (second + ans ) % div;

                }
                ans = second;
            }

            System.out.println(ans);

        }
        //writer.close();
    }
}