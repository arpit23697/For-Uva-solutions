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

int main ()
{
	int k;
	cin >> k;

	set <int> mainSet;
	for (int i =0 ; i <= 20 ; i++)
	{
		mainSet.insert (i);
		mainSet.insert (i*2);
		mainSet.insert (i*3);
	}
	mainSet.insert (50);

	vector <int> vec;
	vec.insert (vec.begin() , mainSet.begin() , mainSet.end());

	int sizeOfVec = vec.size();




	while (1)
	{
		set <tuple <int , int , int>> mySet;
		long long int combinations = 0 , permutations = 0;

		int temp = k;
		if (k <= 180)
		{		
		pair < set <tuple <int , int , int>> :: iterator , bool > pairs;
		for (int a =0 ; a < sizeOfVec && vec[a] <= k ; a++)
			for (int b = a ; b < sizeOfVec && vec[b] <= k - vec[a] ; b++)
				for (int c = b ; c < sizeOfVec && vec[c] <= k - vec[a] - vec[b]; c++)
				{
							if (vec[a] + vec[b] + vec[c] == k)
							{
								
									combinations++;
									if (vec[a] == vec[b] && vec[a] == vec[c])
										permutations += 1;
									else if (vec[a] == vec[b] || vec[b] == vec[c] || vec[a] == vec[c])
										permutations += 3;
									else 
										permutations += 6;
							}	
				}

	}

		if (permutations == 0 && combinations == 0)
			cout << "THE SCORE OF "<< temp <<" CANNOT BE MADE WITH THREE DARTS." << endl;	

		else 
		{
			cout << "NUMBER OF COMBINATIONS THAT SCORES "<< temp << " IS " << combinations <<"." << endl;
			cout << "NUMBER OF PERMUTATIONS THAT SCORES "<< temp << " IS " << permutations <<"." << endl;
		}

		cout << "**********************************************************************" << endl;

		

		cin >> k;
		if (k <= 0)
		{	
			cout << "END OF OUTPUT" << endl;
			break;
		}
	}

	return 0;
}