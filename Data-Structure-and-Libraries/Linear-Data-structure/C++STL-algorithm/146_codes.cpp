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

using namespace std;

int main ()
{
	string str;
	while (true)
	{
		cin >> str;
		if (str == "#")
			break;

		if (next_permutation (str.begin() , str.end()))
			cout << str << endl;
		else
			cout << "No Successor" << endl;
	}
	return 0;
}
