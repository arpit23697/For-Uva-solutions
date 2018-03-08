#include <bits/stdc++.h>
using namespace std;
int n , edges;
vector < vector <int> > graph;
vector <string> mySet;
vector <int> ans;
int indegrees[105];
bool visited[105];

int Find (string x)
{
	int counter = 0;
	for (vector <string> :: iterator itr = mySet.begin () ; itr != mySet.end() ; ++itr)
	{
		if ( (*itr) == x )
		return counter;

		counter++; 
	}
	return counter;
}


void DFS_Khans_rule (){
	queue <int> q;
	for (int i = 0 ; i < n ; i++)
		if (indegrees[i] == 0)
		{
			q.push(i);
			break;
		}

	while (!q.empty())
	{
		
		int vertex = q.front();
		q.pop();
		ans.push_back (vertex);
		visited[vertex] = true;
		for (int i= 0 ; i < graph[vertex].size() ; i++)
		{

			int v = graph[vertex][i];
			indegrees[v]--;	
		}
		for (int i = 0 ; i < n ; i++)
		{
			if (indegrees[i] == 0 && visited[i] == false)
			{
				q.push(i);
				break;
			}
		}

	}	
		
}

int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" ,stdout);

	int cases = 0;
	while (scanf ("%d" , &n) == 1)
	{
		cases++;
		mySet.clear();
		for (int i =0  ; i < n ; i++)
		{
			string temp;
			cin >> temp;
			mySet.push_back(temp);
		}

		graph.clear();
		graph.assign (n , vector <int> ());
		ans.clear();

		memset (indegrees , 0 , sizeof indegrees);
		memset (visited , false , sizeof visited);
		//sort (mySet.begin () , mySet.end());
		scanf ("%d",&edges);
		for (int i = 0 ; i < edges ; i++)
		{
			string a , b;
			cin >> a >> b;
			int x = Find (a);
			int y = Find (b);

			//cout << x << " " << y << endl;
			graph[x].push_back (y);
			indegrees[y]++;
			
		}


		DFS_Khans_rule ();
		printf("Case #%d: Dilbert should drink beverages in this order:", cases);
		for (int i = 0 ; i < n ; i++)
		{	
			cout << " " << mySet[ans[i]];
		}
		cout << "." << endl << endl;


	}
	return 0;
}