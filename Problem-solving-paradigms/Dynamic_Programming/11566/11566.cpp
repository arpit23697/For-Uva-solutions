#include <bits/stdc++.h>
using namespace std;
long long int n , canBeUsed , k; 
int maxWeight;
long long int  wt[1000];
double memo[210][30][1023];
double value[1000];

double solve (int id , int used ,  int remW)
{

	//cout << id << " " << used << " " << remW << endl;
	int temp = remW / 100;

	if (memo[id][used][temp] != -1)
		return memo[id][used][temp];

	if (remW <= 0 )
		return 0;
	if (id >= k)
		return 0;

	if (used >= canBeUsed)
		return 0;

	if (wt[id] > remW)
		return memo[id][used][temp] = solve (id + 1 , used , remW);
	
	
		double ans1 =  solve (id + 1 , used + 1 , remW - wt[id]) ;
		ans1 = value[id] + ans1;	    
	    double ans2 =  solve (id + 1 , used , remW );	
		return memo[id][used][temp] = max (ans1 , ans2);
	
}

int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	while (1)
	{
		int num ;
		int x , t ;
		cin >> num >> x >> t >> k;

		if (num == 0 && k == 0 && x == 0 && t == 0)
			break;


		x = 100 * x;
		t = 110 * t;
		n = num+1;
		maxWeight = n * x - n * t;



		for (int i = 0 ; i < k ; i++)
		{
			cin >> wt[i];
			wt[i] = 110 * wt[i];

			double mean = 0;
			for (int j = 0 ; j < n ; j++)
			{
				double temp;
				cin >> temp;
				mean += temp;
			}
			mean = (mean * 1.0) / n;
			value[i] = mean;
		}
		canBeUsed = 2 * n;

		for (int i = k ; i < 2 * k ; i++)
		{
			wt[i] = wt[i-k];
			value[i] = value[i-k];
		}

		k = 2 * k;

		for (int i =0 ; i < 210 ; i++)
			for (int j =0 ; j < 30 ; j++)
				for (int k =0 ; k < 1023 ; k++)
					memo[i][j][k] = -1;

	//	cout << maxWeight << endl;
	//	for (int i = 0 ; i < k ; i++)
	//		cout << wt[i] << " " << value[i] << endl;

		double ans = solve (0 , 0 , maxWeight);
		printf ("%.2lf\n" , ans);
	}

	fclose (stdin);
	fclose (stdout);
	return 0;
}