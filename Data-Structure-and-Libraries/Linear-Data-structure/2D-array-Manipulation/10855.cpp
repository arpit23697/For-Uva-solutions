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

char Big[500][500];
char small[500][500]; 

int checkInMatrix ( int n , int N )
{
	int ans = 0;

	for (int startX = 0 ; startX <= N-n ; startX++)
	{
		for (int startY = 0 ; startY <= N-n ; startY++)
		{

			int flag = 0;
			{
				for (int i = startX ; i < n+startX ; i++)
				{
					for (int j =startY ; j < n+startY ; j++)
						if ( Big[i][j] != small[i-startX][j - startY] )
						{
							flag++;
							break;
						}

					if (flag == 1)
						break;
				}
				//cout << flag << " " ;

				if (flag == 0)
					ans++;	
			}
			//cout << endl;

		}
	}


return ans;
}

int main ()
{
	while (1)
	{
		int N , n;		
		cin >> N >> n;

		if (N == 0 && n ==0 )
			return 0;



		string str;
		for (int i = 0 ; i < N ; i++)
		{
			cin >> str;
			for (int j= 0; j < N ; j++)
				Big[i][j] = str[j];
		}	

		for (int i = 0 ; i < n ; i++)
		{
			cin >> str;
			for (int j =0 ; j < n ; j++)
				small[i][j] = str[j];
		}

		char small2[n][n];
		char small3[n][n];
		char small4[n][n];

		int ans1 , ans2 , ans3 , ans4;
		ans1 = checkInMatrix ( n , N);
		


		for (int i =0 ; i < n ; i++)
			for (int j =0 ; j < n ; j++)
			{
				small2[i][j] = small[n-j-1][i];
			}

		for (int i =0 ; i < n ; i++)
			for (int j =0 ; j < n ; j++)
				small[i][j] = small2[i][j];



		
		ans2 = checkInMatrix ( n , N);

		for (int i =0 ; i < n ; i++)
			for (int j =0 ; j < n ; j++)
			{
				small3[i][j] = small2[n-j-1][i];
				small[i][j] = small2[n-j-1][i];
			}

		

		ans3 = checkInMatrix ( n , N);

		for (int i =0 ; i < n ; i++)
			for (int j =0 ; j < n ; j++)
			{
				small4[i][j] = small3[n-j-1][i];
				small[i][j] = small3[n-j-1][i];
			}


		ans4 = checkInMatrix ( n , N);

		cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;


	}

	return 0;
}