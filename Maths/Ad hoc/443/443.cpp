#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    set <long long int> mySet;
    int a[4];
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    a[3] = 7;

    mySet.insert (1);
    set <long long int> :: iterator itr;
    itr = mySet.begin();
    long long int b;
    while (mySet.size() < 5842)
    {
        for (int i= 0 ; i < 4 ; i++)
        {
            b = *itr * a[i];
            if (b <= 2000000000)
            mySet.insert(b);
        }
        ++itr;
    }
 
    vector <long long int > ans(5842);
    int m= 0;
    for (itr = mySet.begin() ; itr != mySet.end() ; ++itr)
    {
        ans[m] = *itr;
        m++;
    }
    int n;
    while (1)
    {   
        cin >> n;
        if (n == 0)
        break;

        if (n%10 == 1 && n%100 != 11)
        printf("The %dst humble number is %lld.\n" , n , ans[n-1]);
        else if (n%10  == 2 && n%100 != 12)
        printf("The %dnd humble number is %lld.\n" , n , ans[n-1]);
        else if (n%10  == 3 && n%100 != 13)
        printf("The %drd humble number is %lld.\n" , n , ans[n-1]);
        else 
        printf("The %dth humble number is %lld.\n" , n , ans[n-1]);
    }

    return 0;
}
