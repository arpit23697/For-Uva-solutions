import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.Integer;


class Main {
    public static void main (String [] args) throws IOException {
      //  File in = new File ("in.txt");
        Scanner sc = new Scanner (System.in);

//   File out = new File ("out.txt");
  //   PrintWriter writer = new PrintWriter(out);

        
        int test = sc.nextInt();
     //   System.out.println(test);
        while (test > 0)
        {
            test--;
            int n =0;
            
            int maxi = -1;
            int len = 0;

            String num[] = new String[35];
          
            while(true)
            {

                num[n] = sc.next();
                if (num[n].compareTo("0") == 0)
                break;

                if (num[n].indexOf('.') < 0)
                num[n] = num[n] + '.';
                len = num[n].length();
        
   
                    int temp = num[n].indexOf('.');
                   // System.out.println(len - temp - 1 + " temp");
                    if (len - temp - 1  > maxi)
                    maxi = len - temp -1 ;
                    n++;
            }

            //for (int i= 0 ; i < n ; i++)
           // System.out.println(num[i]);
           // System.out.println(maxi + " maxi ");

            BigInteger sum = BigInteger.ZERO;
            for (int i = 0 ; i < n ; i++)
            {
                String str = "";
                len = num[i].length();
                
                    int temp = len - num[i].indexOf('.') - 1;
                    for (int j =0 ; j < len ; j++)
                    if (num[i].charAt(j) != '.')
                    str = str + num[i].charAt(j);
                
               // System.out.println(str);
                int rem = maxi - temp ;
                 //System.out.println(rem);
                while (rem > 0)
                {
                    rem--;
                    str = str + '0';
                }
                //System.out.println((new BigInteger(str)));
                sum = sum.add ((new BigInteger(str)));
            }
            String str = sum.toString();
    
            String ans2 = "";
            len = str.length();
          //  System.out.println(str + " str " + len + " maxi " + maxi);
            if (maxi < len)
            for (int i=len-1 ; i >= 0  ; i--)
            {
                ans2 = ans2 + str.charAt(i);
                if (i == len - maxi)
                ans2 = ans2 + '.';
            }
            else 
            {
                
                ans2 = "";
                for (int i = 0 ; i < len ; i++)
                if (str.charAt(i) != '-')
                ans2 =str.charAt(i) + ans2; 
                int temp = 0;
                if (str.charAt(0) == '-')
                temp = maxi - len + 1;
                else
                temp = maxi - len;
                while (temp > 0)
                {
                    temp--;
                    ans2 = ans2 + '0';
                }
                ans2 = ans2 + ".0";
                if (str.charAt(0) == '-')
                ans2 = ans2 + '-';
                //System.out.println(ans + "here");     
            }
            len = ans2.length();
            String ans = "";
            if (len > 2 && ans2.charAt(len-1) == '-' && ans2.charAt(len-2) == '.')
            {
                for (int i = 0 ; i < len-2 ; i++)
                ans = ans + ans2.charAt(i);
                ans = ans + ".0-";
            }
            else
            ans = ans2;

            
           //System.out.println(from);
            boolean change = true;
            int index = -1;
            len = ans.length();
            for (int i = 0 ; i< len ; i++)
            {
                if (ans.charAt(i) == '.')
                break;
                if (ans.charAt(i) != '0')
                {
                    change = false;
                    break;
                }
            }
            int imp = -1;
          //  System.out.println(ans);
            for (int i = 0 ; i < ans.length() ; i++)
            {
                if (ans.charAt(i) == '0')
                    imp = i;
                else
                break;
            }
        
            if (!change)
            {
                for (int i = ans.length()-1; i > imp ; i--)
                System.out.print(ans.charAt(i));
                System.out.println();
            }
            else
            {
                int temp = ans.indexOf('.');
                for (int i = ans.length() - 1 ; i > temp ; i--)
                System.out.print(ans.charAt(i));
                System.out.println();
            }
        }
       
        //s.close();
    }
}