import java.util.*;
import java.io.*;
import java.math.*;


class Main {
    public static void main (String [] args) throws IOException {
     //   File in = new File ("in.txt");
        Scanner sc = new Scanner (System.in);

       // File out = new File ("out.txt");
      //  PrintWriter writer = new PrintWriter(out);

        while (sc.hasNext())
        {
            String x = sc.next();
            String y = sc.next();

           // System.out.println(x);
           // System.out.println(y);
            int startX = -1;
            int startY = -1;
            for (int i=0 ; i < x.length() ; i++)
            {
                if (x.charAt(i) >= '0' && x.charAt(i) <= '9')
                {
                   if ( startX < x.charAt(i) - '0' + 1  )
                   startX = x.charAt(i) - '0' + 1 ;
                }
                else
                {
                    if ( startX < x.charAt(i) - 'A' + 11  )
                   startX = x.charAt(i) - 'A' + 11 ;
                }
            }
           // System.out.println(startX);

            for (int i=0 ; i < y.length() ; i++)
            {
                if (y.charAt(i) >= '0' && y.charAt(i) <= '9')
                {
                   if ( startY < y.charAt(i) - '0' + 1  )
                   startY = y.charAt(i) - '0' + 1 ;
                }
                else
                {
                    if ( startY < y.charAt(i) - 'A' + 11  )
                   startY = y.charAt(i) - 'A' + 11 ;
                }
            }

           // System.out.println(startY);
            if (startX < 2)
            startX = 2;
            if (startY < 2)
            startY = 2;

            boolean ans = false;
            int ansX=0, ansY=0;

            for (int i= startX ; i <= 36 ; i++)
            {
                for (int j = startY ; j<= 36 ; j++)
                {
           //         System.out.println(i + " " + j);
                      BigInteger first = new BigInteger(x , i);
                      BigInteger sec = new BigInteger(y , j);
                    //  writer.println(first + " " + sec + " " + i + " " + j);
                    if ( first.compareTo(sec) == 0 )
                    {
                        ans = true;
                        ansX = i;
                        ansY = j;
                        break;
                    }
                }
                if (ans)
                break;
            }
            if (ans == true)
            System.out.println(x + " (base "+ ansX +") = "+y+" (base "+ansY+")");
            else
            System.out.println(x + " is not equal to "+y+" in any base 2..36");
        }
        //writer.close();
    }
}