#include <bits/stdc++.h>
using namespace std;
int adjList[50010];
int n;
int consider[50010];
bool visited[50010];
//int memo[50010];

int DFS (int start)
{
	visited[start] = true;
	int count = 0;
	int u = adjList[start];

	if (visited[u] == false )
		count = 1 + DFS(u);
	visited[start] = false;
	
	consider[start] = count;
	return count;
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

		cin >> n;
		memset (adjList , -1 , sizeof adjList);
		for (int i = 0 ; i < n ; i++)
		{
			int a , b;
			cin >> a >> b;
			a--;
			b--;
			adjList[a] = b;
			consider[a] = -1;
		}

		int ans = -1;
		int ansVertex = -1;
		//memset(memo , -1 , sizeof memo);
		memset (visited , false , sizeof visited);
		for (int i =0  ; i < n ; i++)
		{
			if (consider[i] == -1) DFS(i);

			if (consider[i] > ans)
			{
				ansVertex = i;
				ans = consider[i];
			}
		}

		printf ("Case %d: %d\n" , cases , ansVertex+1);
	}
	return 0;
}