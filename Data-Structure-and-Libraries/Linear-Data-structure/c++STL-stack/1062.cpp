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

using namespace std;

int main ()
{
	int cases = 0;
	while (1)
	{
		cases++;
		string str;
		cin >> str;

		if (str == "end")
			break;

		int numberOfStacks = 0;
		char name[26];

		for (int i =0; i < str.size() ; i++)
		{
			int flag = 0;
			for (int j = 0; j < numberOfStacks ; j++ )
			{
				if (str[i] <= name[j] )
				{
					name[j] = str[i];
					flag = 1;
					break;
				}
			}

			if (flag == 0)
			{
				name [numberOfStacks] = str[i];
				numberOfStacks++;
			}
		}

		cout << "Case " << cases << ": "<<numberOfStacks << endl;
	}

	return 0;
}