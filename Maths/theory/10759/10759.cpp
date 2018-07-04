#include <bits/stdc++.h>
using namespace std;

long long int memo[25][160];


long long int n , x;

long long int eligible (long long int dice_left ,long long  int score)
{
   // cout << dice_left << " " << score << endl;
    if (dice_left == 0)
    {
        if (score < x)
        return memo[dice_left][score] = 0; 
        if (score >= x )
        return memo[dice_left][score] = 1;
    }
    if (memo[dice_left][score] != -1)
    return memo[dice_left][score];

    long long int ans = 0;
    for (int i= 1 ; i <= 6 ; i++)
        ans = ans + eligible(dice_left - 1 ,score + i);
    
    return memo[dice_left][score] = ans;
}

long long int gcd (long long int a ,long long int b)
{
    if (b == 0)
    return a;
    return gcd (b , a%b);
}

int main ()
{
    freopen ("in.txt" , "r" ,stdin);
    freopen ("out.txt" , "w" , stdout);
    
    while (1)
    {
        cin >> n >> x;
        if (n == 0 && x == 0)
        break;

        memset (memo , -1 , sizeof memo);
        long long int a = eligible (n , 0);
        //cout << a << endl;
        if (a == 0)
        {
            cout << "0" << endl;
            continue;
        }
        if (n >= x)
        {
            cout << "1" << endl;
            continue;
        }
        long long int b = pow (6 , n);
        long long int div = gcd (a , b);
        cout << a/div << "/" << b/div << endl;
    
    }
    
    return 0;
}