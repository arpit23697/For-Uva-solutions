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

bool exist (int i , int j , int row , int col)
{
	if (i >= 0 && i < 8 && j >= 0 && j < 8)
		return true;

	return false;
}

int main()
{
	char str[100];
	while (scanf("%s",str) == 1)
	{
		char board[8][8];
		int currentRow = 0;
		int currentCol = 0;

		for (int i = 0; i < strlen(str) ; i++)
		{
			if ( str[i] == '/' )
			{
				currentRow++;
				currentCol = 0;
			}

			else if (str[i] >= '0' && str[i] <= '9')
			{
				int temp = str[i] - '0';
				while (temp--)
				{
					board[currentRow][currentCol] = '0';
					currentCol++;
				}
			}

			else 
			{
				board[currentRow][currentCol] = str[i];
				currentCol++;
			}

		}

		bool attack[8][8];

		for (int i = 0 ; i < 8 ; i++)
			for (int j = 0 ; j < 8 ; j++)
				attack[i][j] = false;

		for (int i =0 ; i < 8 ; i++)
		{
			for (int j =0 ; j < 8 ; j++)
			{
				if (board[i][j] == '0')
					continue;

				else if (board[i][j] == 'p')
				{
					if (exist(i+1 , j-1 , 8 , 8) && board[i+1][j-1] == '0')
						attack[i+1][j-1] = true;
					if (exist(i+1 , j+1 , 8 , 8) && board[i+1][j+1] == '0')
						attack[i+1][j+1] = true;
				}



				else if (board[i][j] == 'P')
				{

					if (exist(i-1 , j-1 , 8 , 8) && board[i-1][j-1] == '0')
						attack[i-1][j-1] = true;
					if (exist(i-1 , j+1 , 8 , 8) && board[i-1][j+1] == '0')
						attack[i-1][j+1] = true;
				} 

				//for knight
				else if (board[i][j] == 'N' || board[i][j] == 'n')
				{
					if (exist(i-2 , j-1 , 8 , 8) && board[i-2][j-1] == '0')
						attack[i-2][j-1] = true;
					if (exist(i-2 , j+1 , 8 , 8) && board[i-2][j+1] == '0')
						attack[i-2][j+1] = true;

					if (exist(i-1 , j+2 , 8 , 8) && board[i-1][j+2] == '0')
						attack[i-1][j+2] = true;
					if (exist(i+1 , j+2 , 8 , 8) && board[i+1][j+2] == '0')
						attack[i+1][j+2] = true;

					if (exist(i+2 , j+1 , 8 , 8) && board[i+2][j+1] == '0')
						attack[i+2][j+1] = true;
					if (exist(i+2 , j-1 , 8 , 8) && board[i+2][j-1] == '0')
						attack[i+2][j-1] = true;

					if (exist(i+1 , j-2 , 8 , 8) && board[i+1][j-2] == '0')
						attack[i+1][j-2] = true;
					if (exist(i-1 , j-2 , 8 , 8) && board[i-1][j-2] == '0')
						attack[i-1][j-2] = true;

				}

				else if (board[i][j] == 'B' || board[i][j] == 'b')
				{
					for (int temp = 1; temp <= 8 ; temp++)
						if (i+temp < 8 && j+temp < 8)
						{	
							if (board[i+temp][j+temp] == '0')
								attack[i+temp][j+temp] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (i-temp >= 0 && j-temp >= 0)
						{	
							if (board[i-temp][j-temp] == '0')
								attack[i-temp][j-temp] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (i-temp >= 0 && j+temp < 8)
						{	
							if (board[i-temp][j+temp] == '0')
								attack[i-temp][j+temp] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (i+temp < 8 && j-temp >= 0)
						{	
							if (board[i+temp][j-temp] == '0')
								attack[i+temp][j-temp] = true;
							else 
								break;
						}

				}
				
				
				else if (board[i][j] == 'R' || board[i][j] == 'r')
				{
				for (int temp = 1; temp <= 8 ; temp++)
						if (i+temp < 8 )
						{	
							if (board[i+temp][j] == '0')
								attack[i+temp][j] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (i-temp >= 0 )
						{	
							if (board[i-temp][j] == '0')
								attack[i-temp][j] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (j+temp < 8)
						{	
							if (board[i][j+temp] == '0')
								attack[i][j+temp] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (j-temp >= 0)
						{	
							if (board[i][j-temp] == '0')
								attack[i][j-temp] = true;
							else 
								break;
						}

				
				}

				else if (board[i][j] == 'Q' || board[i][j] == 'q')
				{
					for (int temp = 1; temp <= 8 ; temp++)
						if (i+temp < 8 && j+temp < 8)
						{	
							if (board[i+temp][j+temp] == '0')
								attack[i+temp][j+temp] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (i-temp >= 0 && j-temp >= 0)
						{	
							if (board[i-temp][j-temp] == '0')
								attack[i-temp][j-temp] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (i-temp >= 0 && j+temp < 8)
						{	
							if (board[i-temp][j+temp] == '0')
								attack[i-temp][j+temp] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (i+temp < 8 && j-temp >= 0)
						{	
							if (board[i+temp][j-temp] == '0')
								attack[i+temp][j-temp] = true;
							else 
								break;
						}

				for (int temp = 1; temp <= 8 ; temp++)
						if (i+temp < 8 )
						{	
							if (board[i+temp][j] == '0')
								attack[i+temp][j] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (i-temp >= 0 )
						{	
							if (board[i-temp][j] == '0')
								attack[i-temp][j] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (j+temp < 8)
						{	
							if (board[i][j+temp] == '0')
								attack[i][j+temp] = true;
							else 
								break;
						}

					for (int temp = 1; temp <= 8 ; temp++)
						if (j-temp >= 0)
						{	
							if (board[i][j-temp] == '0')
								attack[i][j-temp] = true;
							else 
								break;
						}

				

				}

				else if (board[i][j] == 'K' || board[i][j] == 'k')
				{
					if (exist(i-1 , j-1 , 8 , 8) && board[i-1][j-1] == '0')
						attack[i-1][j-1] = true;
					if (exist(i-1 , j , 8 , 8) && board[i-1][j] == '0')
						attack[i-1][j] = true;

					if (exist(i-1 , j+1 , 8 , 8) && board[i-1][j+1] == '0')
						attack[i-1][j+1] = true;
					if (exist(i , j-1 , 8 , 8) && board[i][j-1] == '0')
						attack[i][j-1] = true;

					if (exist(i , j+1 , 8 , 8) && board[i][j+1] == '0')
						attack[i][j+1] = true;
					if (exist(i+1 , j-1 , 8 , 8) && board[i+1][j-1] == '0')
						attack[i+1][j-1] = true;

					if (exist(i+1 , j , 8 , 8) && board[i+1][j] == '0')
						attack[i+1][j] = true;
					if (exist(i+1 , j+1 , 8 , 8) && board[i+1][j+1] == '0')
						attack[i+1][j+1] = true;

				}

			}


		}

		int ans = 0;
			for (int i =0 ; i < 8 ; i++)
				for (int j =0 ; j < 8 ; j++)
					if (attack[i][j] == false && board[i][j] == '0')
						ans+=1;

			cout << ans << endl;
	}

	return 0;
	
}