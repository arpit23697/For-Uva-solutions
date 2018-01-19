//this code lead to time limit exceeds

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

void decompose (string &str , long long int temp)
{
	if (temp >= 0)
		str.push_back('+');
	else
	{
		str.push_back('-');
		temp = -temp;
	}
	if (temp == 0)
		str.push_back('0');
	while (temp)
	{
		str.push_back(temp%10 + '0');
		temp /= 10;
	}
	reverse (str.begin ()+1 , str.end());
}

string addition (string &num1 , string &num2)
{
	string ans = "";
	int carry = 0;

	int n1 = num1.size();
	int n2 = num2.size();

	
 
	if (n1 < n2)
	{
		reverse (num1.begin() , num1.end());
		int x = n2 - n1;
		while(x)
		{
			num1.push_back ('0');
			x--;
		}
		reverse (num1.begin()  , num1.end());
	}
	else if (n2 < n1)
	{
		reverse (num2.begin() , num2.end());
		int x = n1 - n2;
		while(x)
		{
			num2.push_back ('0');
			x--;
		}
		reverse (num2.begin() , num2.end());
	}

	int x;
	int n = num1.size();
	for (int i =0 ; i < n ; i++)
	{
		x = num1[n-1-i] - '0' + num2[n - 1 - i] - '0' + carry;
		char c = x%10 + '0';
		ans = c + ans;
		carry = x / 10;
	}


	return ans;

}

string multiply (string &num1 , string &num2)
{
	if (num1 == "+0" || num1 == "-0")
		return "+0";
	else if (num2 == "+0" || num2 == "-0")
		return "+0";

	int carry = 0;
	string ans = "";
	string shift = "";
	int x;

	int n1 = num1.size();
	int n2 = num2.size();

	for (int i = 0 ; i < n1-1 ; i++)
	{
		string temp = "";
		carry = 0;
		for (int j = 0 ; j < n2-1 ; j++)
		{
			x = (num1[n1-1-i] - '0' )* (num2[n2 - j - 1] - '0' ) + carry;
			char c = x%10 + '0';
			temp = c + temp;
			carry = x / 10;
		}
		if (carry != 0 )
		{
			char c = carry + '0';
			temp = c + temp;
		}
		temp = temp + shift;
		if (ans.size() != 0)
			ans = addition (temp , ans);
		else
			ans = temp;

		shift = shift + '0';
	}

	if (num1[0] == '+' && num2[0] == '+')
		ans = '+' + ans;
	else if (num1[0] == '-' && num2[0] == '-')
		ans = '+' + ans;
	else
		ans = '-' + ans;
	return ans;
}

bool compare (string &num1 , string &num2)
//this function returns true if num1 is greater than num2 
{
	int n1 = num1.size();
	int n2 = num2.size();


	if (num1[0] == '+' && num2[0] == '-')
		return true;
	else if (num1[0] == '-' && num2[0] == '+')
		return false;
	else if (num1[0] == '+' && num2[0] == '+')
	{
		if (n1 > n2)
			return true;
		else if (n2 > n1)
			return false;
		else 
		{
			for (int i = 0 ; i < n1-1 ; i++ )
			{
				if (num1[i + 1] - '0' > num2[i+1] - '0')
					return true;
				else if (num1[i+1] - '0' < num2[i+1] - '0')
					return false;
			}
			return true;
		}
	}
	else
	{
		if (n1 > n2)
			return false;
		else if (n2 > n1)
			return true;
		else 
		{
			for (int i = 0 ; i < n1-1 ; i++ )
			{
				if (num1[i + 1] - '0' > num2[i+1] - '0')
					return false;
				else if (num1[i+1] - '0' < num2[i+1] - '0')
					return true;
			}
			return true;
		}
	}

}




int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	vector <string> numbers;
	
	long long int temp;
	while (scanf ("%lld",&temp)==1)
	{
		numbers.clear();
		numbers.assign (105 , "");

		decompose (numbers[0] , temp);
		int i = 1;
		while (scanf("%lld",&temp) == 1 && temp != -999999)
		{
			decompose (numbers[i] , temp );
			i+=1;
		}
		int n = i;
		string mainAnswer;
		for (int cases = 0 ; cases < n ; cases++)
		{	
			string ans = numbers[cases];
			string product = numbers[cases];
			for (int i = cases+1 ; i < n ; i++)
			{
		
				product = multiply( product , numbers[i]);
				if (compare (ans , product))
					ans = ans;
				else
					ans = product;

				if (product == "+0" || product == "-0")
					product = "+1";
			}

			if (cases == 0)
				mainAnswer = ans;
			else
			{
				if (compare (ans , mainAnswer))
					mainAnswer = ans;
				else
					mainAnswer = mainAnswer;
			}

		}
	

		if (mainAnswer[0] == '-' && mainAnswer[1] != '0')
		cout << mainAnswer << endl;
		else
		{
			for (int i = 1 ; i < mainAnswer.size() ; i++)
				cout << mainAnswer[i] ;
			cout << endl;
		}

	}


	fclose (stdin);
	fclose(stdout);
	return 0;

}