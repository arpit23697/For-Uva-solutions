#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
#include <stack>
#include <tuple>
#include <deque>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main ()
{
    while(1)
    {
        long long int n;
        cin >> n;
        if ( n == 0)
            break;

        priority_queue < int , vector <int> , greater<int>> myQueue;

        long long int ans = 0;

        for (long long int i = 0 ; i < n ; i++)
        {
            long long int temp;
            cin >> temp;
            myQueue.push(temp);
        }

        if (myQueue.size() == 1)
        {
            cout << myQueue.top() << endl;
            continue;
        }

        while (myQueue.size() > 1)
        {
            long long int num1 , num2;
            num1 = myQueue.top();
            myQueue.pop();
            num2 = myQueue.top();
            myQueue.pop();
            ans += num1 + num2;
            myQueue.push(num1 + num2);
        }

        cout << ans << endl;
    }

    return 0;
}