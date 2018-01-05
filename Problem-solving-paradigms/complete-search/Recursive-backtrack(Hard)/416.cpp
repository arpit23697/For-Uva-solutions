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
	char numerals[10][8] = {
		"YYYYYYN",//0
		"NYYNNNN",//1
		"YYNYYNY",//2
		"YYYYNNY",//3
		"NYYNNYY",//4
		"YNYYNYY",//5
		"YNYYYYY",//6
		"YYYNNNN",//7
		"YYYYYYY",//8
		"YYYYNYY",//9
	};



	int n;
	while (scanf("%d",&n) == 1 && n)
	{
		int k, j , i;
		char a[10][n+10];
		for (int i =0 ; i < n ; i++)
			cin >> a[i] ;

		bool flag = false;
		for (i = 9 ; i >= n-1 ; i--)
		{
			int bad[10];
			memset (bad , 0 , sizeof bad);
			for (j = 0; j < n ; j++)
			{
		
				for (k = 0 ; k < 7 ; k++)
				{
					if (bad[k] == 1 && a[j][k] == 'Y')
					break;

					if (a[j][k] == 'N' && numerals[i-j][k] == 'Y')
						bad[k] = 1;
					else if (a[j][k] == 'Y' && numerals[i-j][k] == 'N')
						break;

				}

				if (k != 7)
					break;
			}
			if (j == n)
			{
				flag = true;
				break;
			}
		}

		if (flag == true)
			cout << "MATCH" << endl;
		else
			cout << "MISMATCH" << endl;
	}

	return 0;

}