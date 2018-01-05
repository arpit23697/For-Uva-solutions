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


bool check (vector <int> &vec , int value)
{
	int flag = 0;
	for (int i =0 ; i < vec.size() ; i++)
	{
		if ( ((value / vec[i])%2) == 0 && value % vec[i] < vec[i]-5  )
			flag++;
	}

	if (flag == vec.size())
		return true;



	return false;
}
int main ()
{
	int terminate = 0;

	while (true)
	{
		vector <int> vec;

		int a ;
		scanf("%d",&a);
		//cout << terminate<<"\n";

		if (a == 0 )
		{
			terminate++;
			
		}
		else
		{
			terminate = 0;
			vec.push_back(a);
		}

		if (terminate == 3)
			return 0;

		if (a == 0)
			continue;

		else
		while (true)
		{
			int temp;
			cin >> temp;
			if (temp == 0)
				break;
			else
				vec.push_back(temp);
		
		}



	

		int ans = 19000;

		int minimum = *(min_element(vec.begin () , vec.end()));
		for (int i = minimum ; i <= 18000 ; i++)
		{
			if (check (vec , i))
			{
				ans = i;
				break;
			}
		}

	//	cout << ans << endl;

		if (ans <= 18000)
		{
		

			int minute = ans / 60;
			int hour = minute / 60;
			minute = minute% 60; 
			int second = ans % 60;


			if (minute < 10 && second < 10 )
			cout << "0"<<hour << ":0"<< minute <<":0"<<second<<endl;
			else if (minute < 10)
				cout << "0"<<hour << ":0"<< minute <<":"<<second<<endl;
			else if (second < 10)
				cout << "0"<<hour << ":"<< minute <<":0"<<second<<endl;
			else
				cout << "0"<<hour << ":"<< minute <<":"<<second<<endl;
		}

		else
			cout << "Signals fail to synchronise in 5 hours" << endl;

	}

	return 0;
}