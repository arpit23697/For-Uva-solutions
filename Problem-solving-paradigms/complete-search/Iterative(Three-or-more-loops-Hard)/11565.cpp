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
	int test;
	cin >> test;

	while (test--)
	{
		int A , B , C;
		cin >> A >> B >> C;

		bool sol = false;

		for (int x = -22 ; x <= 22 && !sol ; x++)
			if (x*x <= C)
				for (int y = -100 ; y <= 100 && !sol ; y++)
					if (x != y && x*x + y*y <= C)
						for (int z = -100 ; z <= 100 && !sol ; z++)
						{
							if (y != z && x != z && x + y + z == A && x * y * z == B && (x*x + y*y + z*z == C))
							{
								cout << x << " " << y << " " << z <<endl;
								sol = true;
							}
						}

		if (sol == false)
			cout << "No solution." << endl;
	}

	return 0;
}