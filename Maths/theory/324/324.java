import java.util.*;
import java.math.*;
import java.io.*;

class Main {
    public static void main (String [] args) throws IOException {
      //  File in = new File("in.txt");
        Scanner sc = new Scanner (System.in);

     //  File out = new File ("out.txt");
     //  PrintWriter writer = new PrintWriter (out);


        while(true)
        {   
            int n = sc.nextInt();
            if (n == 0)
            break;
            
            BigInteger ans = BigInteger.valueOf(1);
            for (int i = 2; i <= n ; i++)
            ans = ans.multiply (BigInteger.valueOf(i)); 

            String str = ans.toString();
            int [] freq = new int[10];
            for (int i =0 ; i<10 ; i++)
            freq[i] = 0;


            int len = str.length();
            for (int i= 0 ; i < len ; i++)
            freq[str.charAt(i) - '0']++;       

            System.out.println(n + "! --");
            System.out.printf ("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",freq[0] , freq[1] , freq[2] , freq[3] , freq[4]);
            System.out.printf ("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",freq[5] , freq[6] , freq[7] , freq[8] , freq[9]);
        }
       //writer.close();
    }
}