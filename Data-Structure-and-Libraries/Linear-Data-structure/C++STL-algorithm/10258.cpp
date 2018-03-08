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

using namespace std;

bool comparator ( tuple <int , int , int> a , tuple <int , int , int > b)
{
	if (get<0>(a) != get<0>(b))
		return get<0>(a) > get<0>(b);

	if (get<1>(a) != get<1>(b))
		return get<1>(a) < get<1>(b);

	return get<2>(a) < get<2>(b);
}

int main ()
{
	int test;
	cin >> test;

		
	cin.ignore(100 , '\n');	//for ignoring the characters
	cin.ignore(100 , '\n');
	
	for (int m =0 ; m < test ; m++)
	{	
		int problemSolved[100];
		int penalty [100];
		bool teamToBeDisplayed[100];
		bool questionSolved [100][10];
		int penaltyQuestion [100][10];


		for (int i = 0 ; i < 100 ; i++)
		{
			problemSolved[i] = 0;
			penalty[i] = 0;
			teamToBeDisplayed[i] = false;
		}
		for (int i =0 ; i < 100 ; i++)
			for (int j = 0 ; j < 10 ; j++)
			{
				penaltyQuestion[i][j] = 0;
				questionSolved[i][j] = false;
			}

		

		
		int team , question , time ;
		char status;
		

		while ( cin.peek() != '\n' && cin.peek() != -1)
		{
			cin >> team >> question >> time >> status;
			cin.ignore(100 , '\n');

			teamToBeDisplayed[team-1] = true;

			if (questionSolved[team-1][question-1] == false)
			{
				
				if (status == 'C')
				{
					questionSolved[team-1][question-1] = true;
					problemSolved[team-1]++;
					penalty[team-1] += penaltyQuestion[team-1][question-1] * 20 + time;
				}

				else if (status == 'I')
				{
					penaltyQuestion[team-1][question-1]++;
				}
			}	
		}
		cin.ignore(100 , '\n');

		vector <tuple <int , int , int >> vec;

		for (int i =0 ; i < 100 ; i++)
		{
			vec.push_back(make_tuple(problemSolved[i] , penalty[i] , i+1));
		} 

		sort (vec.begin() , vec.end() , comparator);

		for (int i =0 ; i < 100 ; i++)
		{
			if (teamToBeDisplayed[get<2>(vec[i]) -1] == true)
				cout << get<2>(vec[i]) << " " << get<0>(vec[i]) << " " << get<1>(vec[i]) << endl;
		}



		if (m < test-1)
			cout << endl;
	}

	return 0;
}