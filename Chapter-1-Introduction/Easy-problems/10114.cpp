#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>

using namespace std;

int main ()
{
	while (1)
	{
		int duration;
		double downPayment;
		double loan;
		int n;						//depreciation number

		cin >> duration >> downPayment >> loan >> n ;

		if (duration < 0)
			return 0;

		vector <int> month(n);
		vector <double> depreciation(n);

		for (int i = 0 ; i < n ; i++)
		{
			cin >> month[i];
			cin >> depreciation[i];
		}


		vector <double > depreciationValues(duration+1);

		double temp = loan / duration;
		double currentValue = 0;
		int currentIndex = 0;
		for (int i = 0; i <= duration ; i++)
		{

			if (count(month.begin() , month.end() , i) != 0)
			{
				depreciationValues[i] = depreciation[currentIndex];
				currentValue = depreciation[currentIndex];
				currentIndex++;

				
			}
			else
				depreciationValues[i] = currentValue;

		}

		for (int i=0 ; i <= duration ; i++)
		cout <<i << "  "<< depreciationValues[i] << endl;

		double worth = loan + downPayment;
		double loanLeft = loan;
		int ans = 0;

			worth -= worth * depreciationValues[ans];
			ans++;
		while (1)
		{
			loanLeft -= temp;
			worth -= worth * depreciationValues[ans];


			//cout << loanLeft << "  " << worth << endl;

			if ( loanLeft < worth)
			{
				if ( ans <= 1)
					cout << ans << " month" << endl;

				else
					cout << ans << " months" << endl;	
			
				break;				
			}
			ans++;

		}
	}





	return 0;
}
