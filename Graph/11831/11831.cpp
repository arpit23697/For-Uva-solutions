#include <bits/stdc++.h>
using namespace std;
int n , m , S;
char Arena[101][101];
string inst;

int currentX , currentY ;
char orientation;
int ans;

void update (char x)
{

	if (x == 'D')
	{
		if (orientation == 'N')
		orientation = 'E';
		else if (orientation == 'S')
		orientation = 'W';
		else if (orientation == 'E')
		orientation = 'S';
		else if (orientation == 'W')
		orientation = 'N';	
	}
	else if (x == 'E')
	{
		if (orientation == 'N')
		orientation = 'W';
		else if (orientation == 'S')
		orientation = 'E';
		else if (orientation == 'E')
		orientation = 'N';
		else if (orientation == 'W')
		orientation = 'S';		
	}
	else 
	{
		if (orientation == 'N')
		{
			if (currentX - 1 >= 0 && Arena[currentX-1][currentY] != '#')
			{
				currentX = currentX-1;
				if (Arena[currentX][currentY] == '*')
				{
					ans++;
					Arena[currentX][currentY] = '.';
				}
			}
		}

		else if (orientation == 'S')
		{
			if (currentX + 1 < m && Arena[currentX+1][currentY] != '#')
			{
				currentX = currentX+1;
				if (Arena[currentX][currentY] == '*')
				{
					ans++;
					Arena[currentX][currentY] = '.';
				}
			}
		}

		else if (orientation == 'E')
		{
			if (currentY + 1 < n && Arena[currentX][currentY+1] != '#')
			{
				currentY = currentY+1;
				if (Arena[currentX][currentY] == '*')
				{
					ans++;
					Arena[currentX][currentY] = '.';
				}
			}
		}
		else if (orientation == 'W')
		{
			if (currentY - 1 >= 0 && Arena[currentX][currentY-1] != '#')
			{
				currentY = currentY-1;
				if (Arena[currentX][currentY] == '*')
				{
					ans++;
					Arena[currentX][currentY] = '.';
				}
			}
		}
	}

}


int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);
	while (1)
	{
		cin >> m >> n >> S;
		if (n == 0 && m ==0 && S == 0)
			break;

		ans = 0;

		for (int i = 0 ; i < m ; i++)
			for (int j = 0 ; j < n ; j++)
			{
				cin >> Arena[i][j];
				
				if (Arena[i][j] == 'N' || Arena[i][j] == 'S' || Arena[i][j] == 'L' || Arena[i][j] == 'O')
				{
					currentX = i;
					currentY = j;
					if (Arena[i][j] == 'L')
					orientation = 'E';
					else if (Arena[i][j] == 'O')
					orientation = 'W';
					else
					orientation = Arena[i][j];
					Arena[i][j] = '.';	
 				}

			}

		cin >> inst;
		for (int i = 0 ; i < S ; i++)
			update(inst[i]);

		cout << ans << endl;

	}
	return 0;
}