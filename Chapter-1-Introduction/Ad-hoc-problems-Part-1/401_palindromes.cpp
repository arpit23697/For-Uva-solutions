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

using namespace std;

char REVERSE (char c)
{
	if (c == 'A')
		return 'A';

	if (c == 'E')
		return '3';

	if (c == 'H')
		return 'H';

	if (c == 'I')
		return 'I';

	if (c == 'J')
		return 'L';

	if (c == 'L')
		return 'J';

	if (c == 'M')
		return 'M';

	if (c == 'O')
		return 'O';

	if (c == 'S')
		return '2';

		if (c == 'T')
		return 'T';
		if (c == 'U')
		return 'U';

		if (c == 'V')
		return 'V';

		if (c == 'W')
		return 'W';

		if (c == 'X')
		return 'X';

		if (c == 'Y')
		return 'Y';

	if (c == 'Z')
		return '5';

	if (c == '1')
		return '1';

			if (c == '2')
		return 'S';

			if (c == '3')
		return 'E';

			if (c == '5')
		return 'Z';

			if (c == '8')
		return '8';

		return ' ';	

	
}

int main ()
{
	string str;

	char temp[25] ;
	

	while (scanf("%s",temp) != EOF)
	{
		string str;
		for (int i =0 ; i < strlen(temp) ; i++)
			str.push_back(temp[i]);

		bool palindrome = false;
		bool isMirror = false;

		string reverseString = str;
		reverse (reverseString.begin() , reverseString.end());
		if (reverseString == str)
			palindrome = true;
		else
			palindrome = false;

		string mirror ;
		for (int i =0 ; i < str.length() ; i++)
			mirror.push_back (REVERSE(str[i])) ;

		string revMirror = mirror;
		reverse (revMirror.begin() , revMirror.end());
		if (revMirror == str)
			isMirror = true;
		else
			isMirror = false;

		//cout << str << " " << reverseString << " " << mirror << " " << revMirror << endl;

		cout << str << " -- " ;
		if (!palindrome && !isMirror)
			cout << "is not a palindrome.\n\n";

		else if (palindrome && !isMirror)
			cout << "is a regular palindrome.\n\n";

		else if (!palindrome && isMirror)
			cout << "is a mirrored string.\n\n";

		else if (palindrome && isMirror)
			cout << "is a mirrored palindrome.\n\n";
	
		
		
	
	}

	return 0;
}