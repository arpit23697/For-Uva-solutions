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
	int test;
	cin >> test;

	for (int m =0 ; m < test ; m++)
	{
		deque <string> deck;
		string temp;

		for (int i =0 ;  i < 52 ; i++)
		{
			cin >> temp;
			deck.push_front (temp);
		}

		int counter = 25;
		int Y = 0;
		int X;

		for (int i =0 ; i < 3 ; i++)
		{
			int value;
			if (deck[counter][0] == 'A' || deck[counter][0] == 'K' || deck[counter][0] == 'Q' || deck[counter][0] == 'J' || deck[counter][0] == 'T' )
				value = 10;
			else
				value = deck[counter][0] - '0';


			X = value;
			deck.erase( deck.begin() + 25);

			Y += X;
			int toBeRemoved = 10 - X;
			for (int j =0 ; j < toBeRemoved ; j++)
				deck.erase(deck.begin() + 25);

		}

		reverse (deck.begin() , deck.end());
		cout << "Case " << m+1 << ": " << deck[Y-1] << endl;

	}

	return 0;
}