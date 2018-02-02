#include <bits/stdc++.h>
using namespace std;


int main ()
{
    freopen ("in.txt" , "r" , stdin );
    freopen ("out.txt" , "w" , stdout);

    long long int n;
    int cases = 0;
    scanf("%lld",&n);
    while (1)
    {
    	cases++;
    	vector <pair <int , int>> vec;
    	for (int i = 0 ; i < n ; i++)
    	{
    		int a , b;
    		cin >> a >> b;
    		vec.push_back (make_pair (a , b));
    	}

    	double graph[n+1][n+1];
    	for (int i = 0 ; i < n ; i++)
    	{
    		for (int j = i+1 ; j < n ; j++)
    		{
    			int x = vec[i].first - vec[j].first;
    			int y = vec[i].second - vec[j].second;
    			double temp = sqrt (x * x + y * y);
    			graph[i][j] = temp;
    			graph[j][i] = temp;
    		}
    	}

    	vector <int> vertex;
    	for (int i = 0 ; i < n ; i++)
    		vertex.push_back (i);

    	double ans = 10000000;
    	vector <int> ansMain (n);
    	do 
    	{
    		double temp = 0;
    		for (int i = 1 ; i < n ; i++)
    			temp += graph[vertex[i]][vertex[i-1]];

    		//for (int i =0  ; i < n ; i++)
    		//	cout << vertex[i] << " ";
    		//cout << endl;
    		if (temp < ans)
    		{
    			ans = temp;
    			for (int i =0 ; i < n ; i++)
    				ansMain[i] = vertex[i];

    		}

    	}while (next_permutation (vertex.begin() , vertex.end()));

    	cout << "**********************************************************" << endl;
    	cout << "Network #" << cases << endl;
    	for (int i = 0 ; i < n -1; i++)
    		printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", vec[ansMain[i]].first , vec[ansMain[i]].second , vec[ansMain[i+1]].first , vec[ansMain[i+1]].second  , graph[ansMain[i]][ansMain[i+1]] + 16.0  );

    	printf("Number of feet of cable required is %.2lf.\n"  , ans + (n-1) * 16.0);
    	scanf("%lld",&n);
    	if (n == 0)
    		break;
    }

    return 0;

}