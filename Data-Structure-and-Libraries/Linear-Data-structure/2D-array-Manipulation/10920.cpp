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
	while (1)
	{
		long long int size , value;
		cin >> size >> value;

		if (size == 0 && value == 0)
			break;

		long long int currentX , currentY;
		currentX = (size+1)/2;
		currentY = (size+1)/2;

		long long int temp = 0;

		bool flag1 = false;
		bool flag2 = false;

		value -= 1;
		

		while (value > 0)
		{
			//cout << currentX << " " << currentY << " " << value<<endl;
			if (flag1 == false && flag2 == false)
			{
				temp++;
				if (value >= temp)
				{
					currentX += temp;
					currentY = currentY;
					value-= temp;
				}

				else 
				{
					currentX += value;
					currentY = currentY;
					value = 0;
				}
				//cout << currentX << " " << currentY <<endl;
				flag1 = true;
				flag2 = false;	
			}

			else if (flag1 == true && flag2 == false)
			{
				if (value >= temp)
				{
					currentX = currentX;
					currentY -= temp;
					value -= temp;
				}
				else
				{
					currentX = currentX;
					currentY -= value;
					value = 0;
				}
				//cout << currentX << " " << currentY <<endl;
				flag1 = false;
				flag2 = true;
			}

			else if (flag1 == false && flag2 == true)
			{
				temp++;
				if (value >= temp)
				{
					currentX -= temp;
					currentY = currentY;
					value -= temp; 
				}
				else
				{
					currentX -= value;
					currentY = currentY;
					value = 0;
				}
				//cout << currentX << " " << currentY <<endl;
				flag1 = true;
				flag2 = true;
			}
			else if (flag1 == true && flag2 == true)
			{
				if (value >= temp)
				{
					currentY+= temp;
					currentX = currentX;
					value -= temp;
				}
				else 
				{
					currentX = currentX;
					currentY += value;
					value = 0;
				}
				//cout << currentX << " " << currentY <<endl;
				flag1 = false;
				flag2 = false;
			}
		}

		cout << "Line = " << currentX << ", column = " << currentY << "." << endl;
	}

	return 0;
}