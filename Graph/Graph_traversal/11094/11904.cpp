#include <bits/stdc++.h>
using namespace std;
char Map[21][21];
int m , n;
int startX , startY;
bool visited[21][21];
bool doNotGo[21][21];
int ans;

void DFS (int x , int y)
{
	
 	visited[x][y] = true;
	ans++;
	//cout << x << " " << y  << " " << ans << endl;

	if (y >= 1 && y < n-1)
	{
		if (x-1 >= 0 && Map[x-1][y] == Map[startX][startY] && visited[x-1][y] == false)
			DFS (x-1 , y);
		if (y-1 >= 0 && Map[x][y-1] == Map[startX][startY] && visited[x][y-1] == false)
			DFS (x , y -1);
		if (y+1 < n && Map[x][y+1] == Map[startX][startY] && visited[x][y+1] == false)
			DFS (x , y+1);
		if (x + 1 < m && Map[x+1][y] == Map[startX][startY] && visited[x+1][y] == false)
			DFS (x + 1 , y);
	}	

	if (y == 0)
	{
		//cout << "hi" << endl;
		if (x-1 >= 0 && Map[x-1][y] == Map[startX][startY] && visited[x-1][y] == false)
			DFS (x-1 , y);
		if (Map[x][n-1] == Map[startX][startY] && visited[x][n-1] == false)
			DFS (x , n - 1);
		if (y+1 < n && Map[x][y+1] == Map[startX][startY] && visited[x][y+1] == false)
			DFS (x , y+1);
		if (x + 1 < m && Map[x+1][y] == Map[startX][startY] && visited[x+1][y] == false)
			DFS (x + 1 , y);
	}

	if (y == n-1)
	{
		if (x-1 >= 0 && Map[x-1][y] == Map[startX][startY] && visited[x-1][y] == false)
			DFS (x-1 , y);
		if (y-1 >= 0 && Map[x][y-1] == Map[startX][startY] && visited[x][y-1] == false)
			DFS (x , y -1);
		if ( Map[x][0] == Map[startX][startY] && visited[x][0] == false)
			DFS (x , 0);
		if (x + 1 < m && Map[x+1][y] == Map[startX][startY] && visited[x+1][y] == false)
			DFS (x + 1 , y);
		
	}
}

int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);
	
	while (scanf ("%d %d" , &m , &n) == 2)
	{

		for (int i= 0 ; i < m ; i++)
		{
			string temp;
			cin >> temp;

			for (int j =0  ; j < n ; j++)
				Map[i][j] = temp[j];

		}
		ans = 0;
		cin >> startX >> startY;
		memset (visited , false , sizeof visited);
		

		DFS (startX , startY);
		for (int i = 0 ; i < m ; i++)
			for (int j = 0 ; j < n ; j++)
				doNotGo[i][j] = visited[i][j];

		//cout << ans  << endl;
		//cout << "\n\n\n\n\n ";


		int mainAns = 0;
		for (int i = 0 ; i < m ; i++)
			for (int j = 0 ; j < n ; j++)
			{
				ans = 0;
				if (Map[i][j] == Map[startX][startY] && visited[i][j] == false && doNotGo[i][j] == false)
					DFS (i , j);
		//		cout << ans << endl;

			mainAns = max (ans , mainAns);
			}

		cout << mainAns << endl;
	}
	return 0;
}