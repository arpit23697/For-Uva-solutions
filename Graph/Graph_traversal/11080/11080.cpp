#include <bits/stdc++.h>
using namespace std;
int v , e;
vector <vector <int> > graph;
int color[205];
bool visited[205];

pair <bool , int> BFS (int start)
{
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

	int count1 = 0;
	int count2 = 0;
	for (int i = 0 ; i < v ; i++)
	{

		if (color[i] == 0)
			count1++;
		else if (color[i] == 1)
			count2++;
	}
	
	int ans = min (count1 , count2);


	if (count1 == 0)
		ans = count2;
	if (count2 == 0)
		ans = count1;

	return make_pair ( isbiparite ,ans);


}


int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);
	int test;
	cin >> test;

	while (test--)
	{
		graph.clear();

		cin >> v >> e;
		graph.assign (v , vector <int> ());
		for (int i = 0 ; i < e ; i++)
		{
			int a , b;
			cin >> a >> b;
			graph[a].push_back (b);
			graph[b].push_back (a);
		}

		
		memset (visited , false , sizeof visited);
		int mainAns = 0;
		bool flag = true;
		for (int i = 0 ; i < v ; i++)
		{
			memset (color , -1 , sizeof color);
			
			if (visited[i] == false)
			{
				

				pair <bool , int > p = BFS (i);
				
				if (p.first == false)
				{
					flag = false;
					break;
				}
				mainAns += p.second;
			}
		}

		//cout << v << " " << e << " ";
		if (flag == false)
			cout << "-1" << endl;
		else
			cout << mainAns <<endl;

	}
	return 0;
}