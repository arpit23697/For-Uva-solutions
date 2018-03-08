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

bool isLeapYear (int year)
{
	//cout << "hiteher\n";
	if (year % 400 == 0)
		return true;

	else if (year % 4 == 0 && year % 100 != 0)
		return true;

	else 
	return false; 
}

int Days_in_month (int month , int year)
{
	//cout << "hither";
	if (month == 1)
		return 31;

	else if (month == 2)
	{
		if (isLeapYear (year))
			return 29;
		else
			return 28;
	}
	else if (month == 3)
		return 31;

	else if (month == 4)
		return 30;

	else if (month == 5)
		return 31;

	else if (month == 6)
		return 30;

	else if (month == 7)
		return 31;

	else if (month == 8)
		return 31;

	else if (month == 9)
		return 30;

	else if (month == 10)
		return 31;

	else if (month == 11)
		return 30;

	else if (month == 12)
		return 31;

}


int main ()
{
	while (1)
	{
		int day , month , year;
		long long int increment ;

		cin >> increment >> day >> month >> year;

		if (increment == 0 && day == 0 && month == 0 && year == 0)
			return 0;

		int currentDay , currentMonth , currentYear ;
		currentDay = day;
		currentMonth = month;
		currentYear = year;

		//cout << currentDay << " " << currentMonth << " " << currentYear << " " << increment <<  endl;

		while (increment != 0)
		{	
			//cout << increment <<endl;
			int daysInMonth = Days_in_month(currentMonth , currentYear);
			//cout << daysInMonth << endl;
			if (increment > daysInMonth - currentDay)
			{
				increment -= daysInMonth - currentDay + 1;
				if (currentMonth < 12)
				{
					//cout << "hi ";
					currentDay = 1;
					currentMonth++;
				}
				else if (currentMonth == 12)
				{
					currentDay = 1;
					currentMonth = 1;
					currentYear++;
				}
			}

			else 
			{
				currentDay += increment;
				increment -= increment;
			}
		//cout << currentDay << " " << currentMonth << " " << currentYear << " " << increment<<  endl;


		}

		cout << currentDay << " " << currentMonth << " " << currentYear 	<< endl;
	}

	return 0;
}	