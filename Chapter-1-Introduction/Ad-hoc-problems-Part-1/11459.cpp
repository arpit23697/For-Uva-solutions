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
bool end_game (int a[] , int n)
{
	for (int i =0 ; i < n ; i++)
		if (a[i] == 100)
			return true;

	return false;
}

int check (vector <pair <int , int >> &vec , int value)
{
	for (int i = 0; i < vec.size() ; i++)
		if (value == vec[i].first)
			return vec[i].second;

	return -1;
}
int main ()
{
	int test;
	cin >> test;
	while (test--)
	{
		int numberOfPlayers;
		int numberLadderSnake;
		int Dices;


		cin >> numberOfPlayers >> numberLadderSnake >> Dices;

		vector <pair <int , int >> snakes;
		for (int i =0 ; i < numberLadderSnake ; i++)
		{
			int k , l;
			cin >> k >> l;
			snakes.push_back(make_pair (k , l));
		}

		int currentPlayer = 0;
		int players[numberOfPlayers];


		for (int i =0 ; i < numberOfPlayers ; i++)
			players[i] = 1;

		for (int i =0 ; i < Dices ; i++)
		{
			int value ;
			cin >> value;

			if (end_game (players , numberOfPlayers))
				continue;

			players[currentPlayer] += value;

			if (players[currentPlayer] >= 100)
			{
				players[currentPlayer] = 100;
				if (currentPlayer+1 < numberOfPlayers )
					currentPlayer++;
				else
					currentPlayer = 0;
				continue;
			}

			int jump = check (snakes , players[currentPlayer]);
			if (jump != -1)
			{
				players[currentPlayer] = jump;
				if (currentPlayer+1 < numberOfPlayers )
					currentPlayer++;
				else
					currentPlayer = 0;
				continue; 
			}

			if (currentPlayer+1 < numberOfPlayers )
					currentPlayer++;
				else
					currentPlayer = 0;
		}

		for (int i =0 ; i < numberOfPlayers ; i++)
			cout << "Position of player " << i+1 << " is " << players[i] << "."<< endl;
	}

	return 0;
}