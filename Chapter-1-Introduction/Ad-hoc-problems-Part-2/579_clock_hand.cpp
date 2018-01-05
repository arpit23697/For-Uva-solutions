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

using namespace std;

int main ()
{
	while (1)
	{
		string clock;	
		cin >> clock;

		int hour;
		int minute;
		int len = clock.length();
		if (len == 4)
		{
			hour = clock[0] - '0';
			minute = (clock[2] - '0')*10 + (clock[3] - '0');
		}

		else if (len == 5)
		{
			hour = (clock[0] - '0') * 10 + (clock[1] - '0');
			minute = (clock[3] - '0')*10 + (clock[4] - '0');
		}

		if (hour == 0 && minute == 0)
			return 0;

		double hourDegrees;
		double minDegrees;



		minDegrees = minute * 360 / 60;
		hourDegrees = hour * 360 / 12;
		hourDegrees += 360 / (60.0 * 12) * minute;

//		cout << minDegrees << "  " << hourDegrees <<endl;
		
		if (hourDegrees >= 360)
			hourDegrees = abs (hourDegrees - 360);

		double ans = abs(minDegrees - hourDegrees);

		if (ans <= 180)
			cout << fixed <<setprecision(3) << ans <<endl;
		else
		{
			ans = abs(ans - 360);
			cout << fixed << setprecision(3) << ans <<endl;
		}

	}

	return 0;
}