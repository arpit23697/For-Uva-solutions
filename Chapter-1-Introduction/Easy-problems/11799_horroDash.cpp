#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main ()
{
	int t ;
	cin >> t;
	
	for (int m = 0; m < t ; m++)
	{
		int n;
		cin >> n;
		vector <int> vec(n);
		for (int i =0 ; i < n ; i++)
		{
			cin >> vec[i];
		}

		cout << "Case " << m + 1 << ": " << *(max_element(vec.begin() , vec.end() ) ) << endl;
		
	}

	return 0;
}