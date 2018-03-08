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
	while (1)
	{
		string str;
		//cin.ignore();
		getline (cin , str);

		if (str == "DONE")
			return 0;

		string data;
		for (int i =0 ; i < str.length () ; ++i)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				data.push_back (tolower(str[i]));

			else if (str[i] >= 'a' && str[i] <= 'z')
				data.push_back (tolower(str[i]));

		}

		//cout << data << "  " << str << endl;
		string revString = data;
		reverse (revString.begin() , revString.end());

		if (revString == data)
			cout << "You won't be eaten!" << endl;

		else
			cout << "Uh oh.." << endl;


	}
}