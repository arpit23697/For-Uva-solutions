#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
#include <stack>
#include <tuple>
#include <deque>
#include <map>
#include <set>
#include <queue>

using namespace std;
bool visited[26];


void BFS (int Graph[][26] , int vertex , int* acron , int* tree)
{
	queue <int> q;

	int flag = 0;
	for (int i =0 ; i < 26 ; i++)
		if (Graph[vertex][i] == 1)
		{	
			flag = 1;
			break;
		}

	if (flag == 0)
		(*acron)++;
	else
		(*tree)++;

	visited[vertex] = true;
	q.push(vertex);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i =0 ; i < 26 ; i++)
		{
			if (Graph[v][i] == 1)
			{
				if (visited[i] == false)
				{
					visited[i] = true;
					q.push(i);
				}
			}
		}
	}

}


int main ()
{
	int test;
	cin >> test;
 
	while (test--)
	{
		int Graph[26][26];
		string str;

		for (int i =0 ; i < 26 ; i++)
			for (int j = 0 ; j < 26 ; j++)
				Graph[i][j] = 0;

		while (true)
		{
			cin >> str;
			if (str[0] == '*')
				break;

			Graph[str[1] - 'A'][str[3] - 'A'] = 1;
			Graph[str[3] - 'A'][str[1] - 'A'] = 1;
		}

		for (int i = 0; i < 26 ; i++)
			visited[i] = true;


		cin >> str;

		for (int i =0 ; i < str.length() ; i++)
			if (str[i] != ',')
				visited[str[i] - 'A'] = false; 
  
		int acron = 0;
		int tree = 0;

		for (int i =0 ; i < 26 ; i++)
		{
			if (visited[i] == false)
				BFS (Graph , i , &acron , &tree);
		}
		
		cout << "There are " << tree << " tree(s) and " << acron << " acorn(s)." << endl;
			
	}

	return 0;
}

