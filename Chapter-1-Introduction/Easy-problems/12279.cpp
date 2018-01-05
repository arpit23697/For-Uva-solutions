#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main ()
{
	int temp = 1;
	while (1)
	{

		int k ;
		cin >> k;

		if (k == 0)
			return 0;

		vector <int> vec(k);
		for (int i =0 ; i < k ; i++)
			cin >> vec[i];

		int treatGiven = count (vec.begin() , vec.end() , 0);
		int treat = k - treatGiven;

		cout << "Case " << temp << ": " << treat - treatGiven << endl;
		temp++;
	}

	return 0;
}