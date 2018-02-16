#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> adjList;

int n;
bool reachable[101] , visited[101];

void DFS (int start)
{
	reachable[start] = true;
	for (int j =0 ; j < int(adjList[start].size()) ; j++)
	{
		int u = adjList[start][j];
		if (reachable[u] == false)
			DFS(u);		
	}
}

void DFS_denmination (int start , int del )
{
	visited[start] = true;
	if (start == del)
		return;

		for (int j = 0 ; j < int(adjList[start].size()) ; j++)
		{
			int u = adjList[start][j];
			if (visited[u] == false)
				DFS_denmination( u , del);
		}

}


void printDash ()
{
	cout << "+";
	for (int i = 0 ; i < 2 * n -1 ; i++ )
		cout << "-";
	cout << "+" << endl;
}

int main ()
{
    freopen ("in.txt" , "r" , stdin );
    freopen ("out.txt" , "w" , stdout);

	int test;
	cin >> test;
	

	int cases = 0;
	while (test--)
	{
		cases++;
		cin >> n;
		adjList.clear();
		adjList.assign (n , vector <int> ());

		for (int i= 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				int temp;
				cin >> temp;
				if (temp == 1)
					adjList[i].push_back(j);
			}
		}

		memset (reachable , false , sizeof reachable);
		printf ("Case %d:\n",cases);
		printDash();
		DFS(0);
		for (int i =0  ; i < n ; i++)
		{
			if (reachable[i] == true)
				cout << "|Y";
			else
				cout << "|N";
		}
		cout << "|" << endl;
		printDash ();

		for (int j = 1 ; j < n ; j++)
		{
			memset (visited , false , sizeof visited);

			DFS_denmination( 0 , j);

			//for (int i = 0 ; i < n ; i++)
			//	cout << visited[i] << " " << reachable[i] << endl;
			for (int i = 0 ; i < n ; i++)
			{
				if (j == i && reachable[i] == true)
					cout << "|Y";
				else if (reachable[i] == true && visited[i] == false)
					cout << "|Y";
				else
					cout << "|N";
			}
			cout << "|" << endl;


			printDash();
		}

	}
	return 0;

}