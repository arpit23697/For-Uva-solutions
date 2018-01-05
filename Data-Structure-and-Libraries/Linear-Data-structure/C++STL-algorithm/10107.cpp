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

int main ()
{
	long long int n;
	int temp = 0;
	vector <long long int> vec;
	
 	while (scanf("%lld",&n) == 1)
 	{
 		temp++;
 		vec.push_back(n);
 		sort(vec.begin() , vec.end());
 		if (temp % 2 == 0)
 			cout << (vec[temp/2-1] + vec[temp/2])/2 << endl;
 		else
 			cout << vec[temp/2] << endl;


 	}

 	return 0;
}