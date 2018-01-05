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

	//freopen ("1.txt" , "r" , stdin);
	//freopen ("ans.txt" , "w" , stdout );
	string str;
	cin >> str;
	int queries;
	cin >> queries;

	while (queries--)
	{
		string s;
		cin >> s;

		bool matched = true;
		
		string :: iterator itr = find (str.begin () , str.end () , s[0]);
		int initial = itr - str.begin (); 
		int last = initial;
		if (itr == str.end ())
		{
			cout << "Not matched" << endl;
			continue;
		}
		
		
		for (int i =1 ; i < s.size () ; i++)
		{
			itr = find (itr+1 , str.end() , s[i] );
			if (itr == str.end ())
			{
				matched = false;
				break;
			}

			last = itr - str.begin ();
		}

		if (matched == true)
			cout << "Matched " << initial << " " << last << endl;
		else
			cout << "Not matched" << endl;
	}

	//fclose (stdin);
	//fclose (stdout);
	return 0;
}