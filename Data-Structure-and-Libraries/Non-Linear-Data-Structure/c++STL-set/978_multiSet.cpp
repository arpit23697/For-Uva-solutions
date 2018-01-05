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
#include <multiset>
#include <set>


using namespace std;

int main ()
{
	int test ;
	cin >> test;

	for (int m =0 ; m  < test ; m++)
	{
		int battleField , SG , SB;
		cin >> battleField >> SG >> SB;

		multiset <int > greenArmy;
		multiset <int> blueArmy;

		for (int i =0 ; i < SG ; i++)
		{
			int temp;
			cin >> temp;
			greenArmy.insert(temp);
		}

		for (int i =0 ; i < SB ; i++)
		{
			int temp;
			cin >> temp;
			greenArmy.insert (temp);
		}

		while (1)
		{
			int greenArmySize = greenArmy.size();
			int blueArmySize = blueArmy.size();

			if (greenArmySize == 0 || blueArmySize == 0)
				break;

			multiset <int> :: iterator blue ; 
			multiset <int> :: iterator green ;

			int currentBlue[battleField];
			int currentGreen[battleField];

			int battles = battleField;
			battles = min (greenArmySize , battles);
			battles = min (blueArmySize , battles);	


			for (int i =0 ; i < battles ; i++)
			{
				blue = blueArmy.end();
				green = green.end();
				blue--;
				green--;

				currentBlue[i] = *blue;
				currentGreen[i] = *green;

				blueArmy.erase(blue);
				greenArmy.erase(green);

			}

			for (int i =0 ; i < battles ; i++)
			{
				if (currentGreen[i] < currentBlue[i])
					blueArmy.insert (currentBlue[i] - currentGreen[i]);
				
				else if (currentGreen[i] > currentBlue[i])
					greenArmy.insert (currentGreen[i] - currentBlue[i]);

			}
		}

		int greenArmySize = greenArmy.size();
		int blueArmySize = blueArmy.size();

		if (blueArmySize == 0 && greenArmySize == 0)
			cout << "green and blue died" << endl;

		else if (blueArmySize != 0)
		{	
			cout << "blue wins" << endl;
			for (int multiset <set> :: reverse_iterator itr = blueArmy.rbegin() ; itr != blueArmy.rend() ; ++itr )
				cout << *itr << endl;
		}

		else if (greenArmySize != 0)
		{	
			cout << "green wins" << endl;
			for (int multiset <set> :: reverse_iterator itr = greenArmy.rbegin() ; itr != greenArmy.rend() ; ++itr )
				cout << *itr << endl;
		}


		if (m < test -1)
			cout << endl;
	}

	return 0;

}