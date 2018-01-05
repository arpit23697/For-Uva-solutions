#include <iostream>
#include <string>

using namespace std;

int main ()
{
	while (1)
	{
		int k;
		cin >> k;

		if (k == 0)
			return 0;

		int x , y;
		cin >> x >> y;

		while (k--)
		{
			int a , b ;			//to be compared
			cin >> a >> b;

			if (a == x)
				cout << "divisa" << endl;

			else if (b == y)
				cout << "divisa" << endl;

			else if (a < x && b < y )
				cout << "SO" << endl;

			else if (a < x && b > y)
				cout << "NO" << endl;

			else if (a >x && b < y)
				cout << "SE" << endl;

			else if (a > x && b > y)
				cout << "NE" << endl;
		}
	}

	return 0;
}