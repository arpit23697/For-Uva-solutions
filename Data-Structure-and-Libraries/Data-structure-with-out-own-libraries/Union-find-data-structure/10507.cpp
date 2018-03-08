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

bool allAwaken (bool a[]  , int n)
{
	for (int i =0 ; i < n ; i++)
		if (a[i] == false)
			return false;

	return true;
}

int connectedToActive ( int sleptAreas , int c[][26]  , bool awaken[] , int x)
{
	int ans =0;
	for (int i =0; i < sleptAreas ; i++)
		if (c[x][i] == 1 && awaken[i] == true )
			ans ++;

	return ans;
}

int main ()
{
	int sleptAreas;
	int c[26][26];




	map <char , int> myMap;
	int connection;
	int flag = 0;
	while (cin.peek() != -1)
	{

		if (flag == 0)
		{	
			cin >> sleptAreas;
			flag = 1;
		}

		else
		{
			cin.ignore(100 , '\n');
			cin >> sleptAreas;
		}

		for (int i =0 ; i < 26 ; i++)
			for (int j =0 ; j < 26 ; j++)
				c[i][j] = 0;

		bool awaken[sleptAreas];
		awaken[0] = true;
		awaken[1] = true;
		awaken[2] = true;

		for (int i = 3 ; i < sleptAreas ; i++)
			awaken[i] = false;



		cin >> connection;
		int x = 3;
		string str;
		cin >> str;
		myMap.insert (make_pair (str[0] , 0));
		myMap.insert (make_pair (str[1] , 1));
		myMap.insert (make_pair (str[2] , 2));

		pair < map <char , int > :: iterator , bool> pair_retrieve;

		for (int i =0 ; i < connection ; i++)
		{
			cin >> str;
			

			pair_retrieve = myMap.insert (make_pair (str[0] , x) );
			if (pair_retrieve.second == true)
				x++;

			pair_retrieve = myMap.insert (make_pair ( str[1] , x ));
			if (pair_retrieve.second == true)
				x++;

			

			c[myMap[str[1]]][myMap[str[0]]] = 1;
			c[myMap[str[0]]][myMap[str[1]]] = 1;
		}
		cin.ignore(100 , '\n');
		
		int ans;
		for (ans =0 ; ans < 26 ; ans++)
		{ 

			if (allAwaken (awaken , sleptAreas))
				break;

			vector <int> vec;
			for (int i =0; i < sleptAreas ; i++)
			{
				if (awaken[i] == true)
					continue;

				if(connectedToActive (sleptAreas , c , awaken , i) >= 3)
					vec.push_back(i);
			}

			for (int i = 0; i < vec.size() ; i++)
				awaken[vec[i]] = true;
		}

		if (allAwaken(awaken , sleptAreas))	
			cout << "WAKE UP IN, "<< ans <<", YEARS" << endl;
		else
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
	}
return 0;		
	 	
}
