#include <bits/stdc++.h>
using namespace std;
int n , edges;
vector < vector <int> > graph;
bool visited[205];
int color[205];

void BFS (int start)
{
	queue <int> q;
	q.push (start);
	visited[start] = true;

	color[start] = 0;

	while (!q.empty ())
	{


		int vertex = q.front();
		
		q.pop();


		for (int i = 0 ; i < (int)graph[vertex].size() ; i++)
		{
			int v = graph[vertex][i];
			if (visited[v] == false )
			{
				visited[v] = true;
				q.push(v);
				if (color[vertex] == 0)
				color[v] = 1;
				else
					color[v] = 0;
			}
			
		}
		
	}
}

int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" ,stdout);

	while (1)
	{
		scanf ("%d", &n);
		if (n== 0)
			break;

		scanf ("%d",&edges);
		graph.clear();
		graph.assign (n , vector <int >());
		for (int i = 0 ; i < edges ; i++)
		{
			int a , b;
			cin >> a >>b;
			graph[a].push_back (b);
			graph[b].push_back (a);
		}

		memset (visited , false , sizeof visited);
		memset (color , -1 , sizeof color);

		BFS (0);
		bool ans = true;
		

		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < graph[i].size() ; j++)
			{
				int u = i;
				int v = graph[i][j];
				if (color[u] == color[v])
				{
					ans = false;
					break;
				}
			}

			if (!ans)
				break;
		}
		if (!ans)
			cout << "NOT BICOLORABLE." << endl;
		else
			cout << "BICOLORABLE." << endl;

	}

	return 0;

}