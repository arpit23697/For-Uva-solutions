#include <iostream>
#include <string>

using namespace std;

int main ()
{
	int t ;
	cin >> t;

	while (t--)
	{
		int m , n;
		cin >> m  >> n;

		m = m-2 ;
		n = n-2;

		int temp1 = m/3;
		if (m %3 != 0)
			temp1 += 1;

		int temp2 = n/3;
		if (n%3 != 0)
			temp2+= 1;

		cout << temp1 * temp2 << endl;
	}

	return 0;
}