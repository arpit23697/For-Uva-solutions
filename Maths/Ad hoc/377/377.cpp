#include <bits/stdc++.h>
using namespace std;

//'-1' means no carry 
vector <char> num1, num2;

int Recognition (char x)
{
    if (x == 'V')
    return 0;
    if (x == 'U')
    return 1;
    if (x == 'C')
    return 2;
    if (x == 'D')
    return 3;
}

char rev (int x)
{
    if (x == 0)
    return 'V';
    if (x == 1)
    return 'U';
    if (x == 2)
    return 'C';
    if (x == 3)
    return 'D';
}

void addition ()
{
    int sum = 0;
    int temp = 0;
    int carry = 0;
    for (int i= 0 ; i < 10 ; i++)
    {
        sum = carry + Recognition(num1[i]);
        carry = sum / 4;
        sum = sum % 4;

        sum = sum + Recognition(num2[i]);
        num2[i] = rev (sum % 4);
        carry += sum / 4;
    }
}

void Right ()
{
    for (int i = 0 ; i < 9 ; i++)
    num2[i] = num2[i+1];
    num2[9] = 'V';
}
void left ()
{
    for (int i = 9 ; i> 0 ; i--)
    num2[i] = num2[i-1];
    num2[0] = 'V';
}

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    int test;
    cin >> test;
    cout << "COWCULATIONS OUTPUT" << endl;
    while (test--)
    {
        num1.clear();
        num2.clear();
        string str;
        cin >> str;
      // str = "VVCDU";
        for (int i = 4 ; i >= 0 ; i--)
        num1.push_back(str[i]);

        cin >> str;
      
        for (int i = 4 ; i >= 0 ; i--)
            num2.push_back(str[i]);


        for (int i= 0 ; i < 5 ; i++)
        {
            num1.push_back ('V');
            num2.push_back('V');
        }
      /*  for (int i= 9 ; i>=0 ; i--)
        cout << num1[i];
        cout << endl;

        for (int i= 9 ; i>=0 ; i--)
        cout << num2[i];
        cout << endl;
*/
        char operation;
        for (int i= 0 ; i < 3 ; i++)
        {
            cin >> operation;
            if (operation == 'A')
            addition();
            else if (operation == 'R')
            Right();
            else if (operation == 'L')
            left();
        }
        cin >> str;
        bool ans = true;
        for (int i = 7 ; i >= 0 ; i--)
        {
            if (str[i] != num2[7-i])
            {
                ans = false;
                break;
            }
        }
        if (ans)
        cout << "YES" << endl;
        else 
        cout << "NO" << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}