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
	while (true)
	{
		string str;
		getline (cin , str);

		if (str == "Game  Over")
			return 0;

		if (str == "Game Over")
			return 0;

		vector <char> vec;
		for (int i =0 ; i < str.length() ; i++)
		{
			if ( (str[i] >= '0' && str[i] <= '9') || str[i] == 'X' || str[i] == '/')
				vec.push_back(str[i]);
		}

		int ans = 0;
		vector <int> score;
		for (int i =0 ; i < vec.size() ; i++)
		{
			if (vec[i] <= '9' && vec[i] >= '0')
				score.push_back((vec[i] - '0') );

			else if (vec[i] == '/')
				score.push_back(10 - (vec[i-1] - '0'));

			else if (vec[i] == 'X')
				score.push_back(10);
		}

		//for (int i =0 ; i < vec.size() ; i++)

		int counter = 0;
		vector <int > frames(10);
		int temp = 1;
		int i =0;
		while (counter < 10)
		{
			if (vec[i] <= '9' && vec[i] >= '0' && temp == 1)
			{
				frames[counter] += score[i];
				temp = 2;
			}

			else if (vec[i] <= '9' && vec[i] >= '0' && temp == 2)
			{
				frames[counter] += score[i];
				temp = 1;
				counter++;
			}

			else if (vec[i] == '/')
			{
				frames[counter] += score[i] + score[i+1];
				temp = 1;
				counter++;
			}
			else if (vec[i] == 'X')
			{
				frames[counter] += score[i] + score[i+1] + score[i+2];
				temp = 1;
				counter++;
			}
			i++;
				//cout << vec[i] << " " << score[i] <<" " << ans<<  endl;
		}

		for (int i =0 ; i < 10 ; i++)
		{
			//cout << i << " " <<frames[i] << endl;
			ans += frames[i];
		}

		cout << ans << endl;
	}

	return 0;
}