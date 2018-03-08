#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0 ; i < t ; i++)
	{
		vector <int> vec(3);
		for (int j = 0 ; j < 3 ; j++)
			cin >> vec[j];

		int min = *(min_element (vec.begin() , vec.end()));
		int max = *(max_element (vec.begin() , vec.end()));

		if (vec[0] != min && vec[0] != max)
			cout << "Case "<< i+1 << ": "  << vec[0] << endl;

		else if (vec[1] != min && vec[1] != max)
			cout << "Case "<< i+1 << ": "  << vec[1] << endl;

		else if (vec[2] != min && vec[2] != max)
			cout << "Case "<< i+1 << ": "  << vec[2] << endl;
	}

	return 0;
}