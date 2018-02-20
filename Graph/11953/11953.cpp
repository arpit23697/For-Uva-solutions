#include <bits/stdc++.h>
using namespace std;
char Map[105][105];
int n;
bool visited[105][105];

bool ship ;

void DFS (int x , int y)
{
	
 	visited[x][y] = true;
	if (Map[x][y] == 'x')
		ship = true;
	//cout << x << " " << y  << " " << ans << endl;


		if (x-1 >= 0 && (Map[x-1][y] == 'x' || Map[x-1][y] == '@') && visited[x-1][y] == false)
			DFS (x-1 , y);
		if (y-1 >= 0 && (Map[x][y-1] == 'x' || Map[x][y-1] == '@') && visited[x][y-1] == false)
			DFS (x , y -1);
		if (y+1 < n && (Map[x][y+1] == 'x' || Map[x][y+1] == '@') && visited[x][y+1] == false)
			DFS (x , y+1);
		if (x + 1 < n && (Map[x+1][y] == 'x' || Map[x+1][y] == '@') && visited[x+1][y] == false)
			DFS (x + 1 , y);



}

int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);
	int test;
	cin >> test;

	int cases = 0;
	
	while (test--)
	{
		cin >> n;
		cases++;
		for (int i= 0 ; i < n ; i++)
		{
			string temp;
			cin >> temp;

			for (int j =0  ; j < n ; j++)
				Map[i][j] = temp[j];

		}

		memset (visited , false , sizeof visited);
		
		int ans = 0;
		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				ship = false;
				if ( (Map[i][j] == 'x' || Map[i][j] == '@' ) && visited[i][j] == false )
					DFS (i , j);
				if (ship)
					ans++;
			}
		}
			
		printf("Case %d: %d\n" , cases , ans);
	}
	return 0;
}