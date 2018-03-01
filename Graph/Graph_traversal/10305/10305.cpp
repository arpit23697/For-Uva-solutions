#include <bits/stdc++.h>
using namespace std;
int m , n;
vector <vector <int >> graph;
vector <int> ans;

bool visited[105];

void DFS (int start)
{
	//cout << "hii" << endl;
	visited[start] = true;
	for (int i = 0 ; i < int(graph[start].size()) ; i++)
	{
		int v = graph[start][i];
		if (visited[v] == false)
			DFS(v);
	}
	ans.push_back(start);
}


int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	while (scanf ("%d %d",&n , &m ) == 2)
	{

		if (m == 0 && n ==0 )
			break;

		//cout << m << " "<< n << endl;
		graph.assign (n , vector <int> ());
		for (int i =0 ; i < m ; i++)
		{
			int a , b;
			cin >> a >> b;
			a--;
			b--;
			graph[a].push_back (b);
		//	cout << "hii " << endl;
		}
			ans.clear();
			memset (visited , false , sizeof visited);

			for (int i= 0 ; i < n ; i++)
				if (visited[i] == false)
					DFS(i);

			for (int i = int (ans.size())-1 ; i >= 0 ; i--)
			{
				if (i ==0 )
					cout << ans[i]+1 << endl;
				else
					cout << ans[i]+1 << " ";
			}
	}
	return 0;
}