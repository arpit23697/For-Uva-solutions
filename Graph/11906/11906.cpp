#include <bits/stdc++.h>
using namespace std;
int rows , cols , m , n;
int water;
bool accessible[101][101];
bool visited[101][101];

int even , odd;

void BFS (int a , int b)
{
	visited[a][b] = true;
	queue <pair <int , int >>q;
	q.push (make_pair(a , b));
	

	while (!q.empty())
	{
		set <pair <int , int>> temp;
		pair <int , int> p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;

		int count = 0 ;
		if (x + m < rows && y + n < cols && accessible[x+m][y+n] == true)
		{
			temp.insert (make_pair(x+m , y+n));
			if (visited[x+m][y+n] == false)
			{
				visited[x+m][y+n] = true;
				q.push(make_pair(x+m , y+n));
			}
		}

		if (x + m < rows && y - n >= 0 && accessible[x+m][y-n] == true)
		{
			temp.insert (make_pair(x+m , y-n));
			if (visited[x+m][y-n] == false)
			{
				visited[x+m][y-n] = true;
				q.push(make_pair(x+m , y-n));
			}
		}
		if (x - m >= 0 && y + n < cols && accessible[x-m][y+n] == true )
		{
			temp.insert (make_pair(x-m , y+n));
			if (visited[x-m][y+n] == false)
			{
				visited[x-m][y+n] = true;
				q.push(make_pair(x-m , y+n));
			}
		}
		if (x - m >= 0 && y - n >= 0 && accessible[x-m][y-n] == true)
		{
			temp.insert (make_pair(x-m , y-n));
			if (visited[x-m][y-n] == false)
			{
				visited[x-m][y-n] = true;
				q.push(make_pair(x-m , y-n));
			}
		}



		if (x + n < rows && y + m < cols && accessible[x+n][y+m] == true )
		{
			temp.insert (make_pair(x+n , y+m));
			if (visited[x+n][y+m] == false)
			{
				visited[x+n][y+m] = true;
				q.push(make_pair(x+n , y+m));
			}
		}

		if (x + n < rows && y - m >= 0 && accessible[x+n][y-m] == true)
		{
			temp.insert (make_pair(x+n , y-m));
			if (visited[x+n][y-m] == false)
			{
				visited[x+n][y-m] = true;
				q.push(make_pair(x+n , y-m));
			}
		}
		if (x - n >= 0 && y + m < cols && accessible[x-n][y+m] == true)
		{
			temp.insert (make_pair(x-n , y+m));
			if (visited[x-n][y+m] == false)
			{
				visited[x-n][y+m] = true;
				q.push(make_pair(x-n , y+m));
			}
		}
		if (x - n >= 0 && y - m >= 0 && accessible[x-n][y-m] == true)
		{
			temp.insert (make_pair(x-n , y-m));
			if (visited[x-n][y-m] == false)
			{
				visited[x-n][y-m] = true;
				q.push(make_pair(x-n , y-m));
			}
		}

		//cout << x << " " << y << " count" << count << endl;
		if (temp.size()%2 == 0)
			even++;
		else
			odd++;

	}
}

void BFS_equal (int a , int b)
{

	visited[a][b] = true;
	queue <pair <int , int >>q;
	q.push (make_pair(a , b));

	while (!q.empty())
	{

		pair <int , int> p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;

		int count = 0 ;
		if (x + m < rows && y + m < cols && accessible[x+m][y+m] == true )
		{
			count++;
			if (visited[x+m][y+m] == false)
			{
				visited[x+m][y+m] = true;
				q.push(make_pair(x+m , y+m));
			}
		}

		if (x + m < rows && y - m >= 0 && accessible[x+m][y-m] == true)
		{
			count++;
			if (visited[x+m][y-m] == false)
			{
				visited[x+m][y-m] = true;
				q.push(make_pair(x+m , y-m));
			}
		}
		if (x - m >= 0 && y + m < cols && accessible[x-m][y+m] == true)
		{
			count++;
			if (visited[x-m][y+m] == false)
			{
				visited[x-m][y+m] = true;
				q.push(make_pair(x-m , y+m));
			}
		}
		if (x - m >= 0 && y - m >= 0 && accessible[x-m][y-m] == true)
		{
			count++;
			if (visited[x-m][y-m] == false)
			{
				visited[x-m][y-m] = true;
				q.push(make_pair(x-m , y-m));
			}
		}

		if (count%2 == 0)
			even++;
		else
			odd++;

	}

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
		cases++;
		cin >> rows >> cols >> m >> n;
		int water;
		cin >> water;
		memset (accessible , true ,sizeof accessible);
		memset (visited , false ,sizeof visited );
		even = 0;
		odd = 0;
		for (int i= 0 ; i < water ; i++)
		{
			int a , b;
			cin >> a >> b;
			accessible[a][b] = false;
		}

		if (m == n)
			BFS_equal(0 , 0);
		else
			BFS (0 , 0);

		printf ("Case %d: %d %d\n",cases , even , odd);

	}
	return 0;
}