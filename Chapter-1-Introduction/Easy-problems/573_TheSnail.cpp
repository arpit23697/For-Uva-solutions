#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <stdio.h>

using namespace std;

int main()
{
	while (1)
	{
		int height , fall ;
		double fatigue , canClimb;

		cin >> height >> canClimb >> fall >> fatigue;

		if (height == 0)
		break;

		fatigue = .01 * fatigue;
		fatigue = canClimb * (fatigue);
		bool day = true;
		double currentPos = 0;

		int ans = 0;
		while (1)
		{
			
			if (day)
			{
				currentPos += canClimb;
				if (canClimb > 0)
				canClimb = canClimb - fatigue;
				day = false;
				ans++;
			}

			else
			{
				currentPos -= fall;
				day = true;
			}

			//cout << currentPos << endl;


			if (currentPos > height)
			{
				cout << "success on day " << ans << endl;
				break;
			}
			else if (currentPos < 0)
			{
				cout << "failure on day " << ans << endl;
				break;
			}
		} 
	}
	return 0;
}