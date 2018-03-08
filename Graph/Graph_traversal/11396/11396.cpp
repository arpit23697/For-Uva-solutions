#include <bits/stdc++.h>
using namespace std;
int v , e;
vector <vector <int> > graph;
int color[305];
bool visited[305];

bool BFS (int start)
{
	//cout << start << endl;
	queue <int> q;
	visited[start] = true;
	q.push(start);
	color[start] = 0;

	bool isbiparite = true;

	while (!q.empty ())
	{
		int vertex = q.front();
		q.pop();
		for (int  i = 0 ; i < graph[vertex].size() ; i++)
		{
			int u = graph[vertex][i];

			if (visited[u] == false)
			{
				visited[u] = true;
				q.push (u);
				color[u] = 1 - color[vertex] ;
			}
			else if (color[u] == color[vertex])
			{
				isbiparite = false;
				break;
			}
		}

	}
	return isbiparite;


}


int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);
	
	while (1)
	{
		graph.clear();
		cin >> v;
		if (v == 0)
			break;

		graph.assign (v , vector <int> ());
		while (1)
		{
			int a , b;
			cin >> a >> b;


			if (a == 0 && b == 0 )
				break;
			
			a--;
			b--;
	
			graph[a].push_back (b);
			graph[b].push_back (a);
		}

		
		memset (visited , false , sizeof visited);
		memset (color , -1 , sizeof color);

		bool flag = true;

		for (int i = 0 ; i < v ; i++)
		{

			if (visited[i] == false)
			{
				flag =  BFS (i);
				if (flag == false)
					break;
			}
		}

		//cout << v << " " << e << " ";
		if (flag == false)
			cout << "NO" << endl;
		else
			cout << "YES" <<endl;

	}
	return 0;
}