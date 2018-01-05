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

typedef pair<int,int> ii;

int main ()
{
	int rows , cols;
	while (scanf("%d %d", &rows , &cols) == 2)
	{

		vector < vector <ii> > matrix;
		vector < vector <ii> > matrixT;

		matrix.assign ( rows , vector <ii> ());
		matrixT.assign ( cols , vector <ii> ());

		for (int currentRow = 0 ; currentRow < rows ; currentRow++)
		{
			int k;
			cin >> k;

			if (k == 0)
			{
				cin.ignore (100 , '\n');
				cin.ignore (100 , '\n');
			}	

			int pos[k];
			int weight[k];

			for (int i =0 ; i < k ; i++)
				cin >> pos[i];

			for (int i=0 ; i < k ; i++)
				cin >> weight[i];

			for (int i =0 ; i < k ; i++)
				matrix[currentRow].push_back (make_pair (pos[i]-1 , weight[i]));

		}

		for (int i =0 ; i < rows ; i++)
			for (int j = 0; j < matrix[i].size() ; j++)
			{
				ii temp = matrix[i][j];
				matrixT[temp.first].push_back (make_pair ( i , temp.second));
				
			}

		cout << cols <<" "<<rows << endl;
		for (int i =0; i < cols ; i++)
		{
			if (matrixT[i].size() == 0)
			{
				cout << "0\n";
				cout << endl;
				continue;
			}

			cout << matrixT[i].size() << " "; 
			for (int j =0 ; j < matrixT[i].size() ; j++)
			{
				ii temp = matrixT[i][j];				
				if (j < matrixT[i].size() - 1)
				cout << temp.first+1 << " ";
				else
				cout << temp.first+1 << endl;
			}

			for (int j = 0 ; j < matrixT[i].size() ; j++)
			{
				ii temp = matrixT[i][j];
				if (j < matrixT[i].size()-1)
					cout << temp.second << " ";
				else
					cout << temp.second << endl;
			}

		}
	}

	return 0;
}
