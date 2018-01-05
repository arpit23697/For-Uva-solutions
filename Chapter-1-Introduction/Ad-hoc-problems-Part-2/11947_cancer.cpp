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
string scorpio = "" ;


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
vector <int> getDate (int day , int month , int year)
{
		//int day , month , year;
		long long int increment = 7*40;

		//cin >> increment >> day >> month >> year;

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

		vector <int> ans;
		ans.push_back(currentDay);
		ans.push_back(currentMonth);
		ans.push_back(currentYear);

		return ans;
	}

	void getScorpio (int day , int month)
	{
		if ((month == 1 && day >= 21) || (month == 2 && day <= 19))
		scorpio = "aquarius";

		if ((month == 2 && day >= 20) || (month == 3 && day <= 20))
		scorpio =  "pisces";

		if ((month == 3 && day >= 21) || (month == 4 && day <= 20))
		scorpio = "aries";

			if ((month == 4 && day >= 21) || (month == 5 && day <= 21))
		scorpio =  "taurus";

			if ((month == 5 && day >= 22) || (month == 6 && day <= 21))
		scorpio =  "gemini";

			if ((month == 6 && day >= 22) || (month == 7 && day <= 22))
		scorpio =  "cancer";

			if ((month == 7 && day >= 23) || (month == 8 && day <= 21))
		scorpio = "leo";

			if ((month == 8 && day >= 22) || (month == 9 && day <= 23))
		scorpio = "virgo";

			if ((month == 9 && day >= 24) || (month == 10 && day <= 23))
		scorpio = "libra";

			if ((month == 10 && day >= 24) || (month ==11 && day <= 22))
		scorpio = "scorpio";

			if ((month == 11 && day >= 23) || (month == 12 && day <= 22))
		scorpio = "sagittarius";

			if ((month == 12 && day >= 23) || (month == 1 && day <= 20))
		scorpio = "capricorn";
	}
int main ()
{
	int test;
	cin >> test;
	int m = 0;

	while (test--)
	{
		m++;
		string data;
		cin >> data;

		vector <int> vec;
		for (int i =0 ; i < data.length() ; i++)
			vec.push_back(data[i] - '0');

		int month , day , year;

		month = vec[0] * 10 + vec[1];
		day = vec[2]*10 + vec[3];
		year = vec[4] * 1000 + vec[5] * 100 + vec[6] * 10 + vec[7];

		vector <int> current;
		

		current = getDate (day , month , year);
		//cout << current[0] << endl;
		getScorpio(current[0] , current[1]);
		if (current[1] < 10 && current[0] < 10)
			cout << m  << " " <<  "0" <<current[1] << "/" << "0" << current[0] << "/" << current[2] << " " << scorpio << endl;

		else if (current[1] < 10)
		cout << m  << " " <<  "0" <<current[1] << "/" << current[0] << "/" << current[2] << " " << scorpio << endl;

		else if (current[0] < 10)
		cout << m  << " " <<current[1] << "/" << "0" <<current[0] << "/" << current[2] << " " << scorpio << endl;			

		else
			cout << m  << " "  <<current[1] << "/" << current[0] << "/" << current[2] << " " << scorpio << endl;

	}

	return 0;
}