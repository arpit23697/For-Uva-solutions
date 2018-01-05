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
	
	vector <string> vec;
	vector <string> duplicate;

	while (1)
	{
		string str;
		cin >> str;
		string data; 	

		if (str == "#")
			break;

		vec.push_back (str);

		for (int i =0 ; i < str.length () ; ++i)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				data.push_back (tolower(str[i]));

			else if (str[i] >= 'a' && str[i] <= 'z')
				data.push_back (tolower(str[i]));

		}

		sort (data.begin() , data.end());
		duplicate.push_back(data);
	}

	sort (vec.begin() , vec.end());

	//for (int  i = 0 ; i < vec.size() ; i++)
		//cout << vec[i] << "  " << duplicate[i] << endl;
	
	for (int i = 0 ; i < vec.size() ; i++)
	{

		string temp;


		for (int j =0 ; j < vec[i].length () ; ++j)
		{
			if (vec[i][j] >= 'A' && vec[i][j] <= 'Z')
				temp.push_back (tolower(vec[i][j]));

			else if (vec[i][j] >= 'a' && vec[i][j] <= 'z')
				temp.push_back (tolower(vec[i][j]));

		}
		//cout << temp;

		sort (temp.begin() , temp.end());

		if (count (duplicate.begin() , duplicate.end() , temp) == 1)
			cout << vec[i] << endl;


	}

	return 0;


}	