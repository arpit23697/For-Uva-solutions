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

int main ()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		vector <pair <int , int >> vec;
		for (int i =0 ; i < n ; i++)
		{
			int a , b;
			cin >> a >> b;
			vec.push_back (make_pair (a , b));
		}

		stack <int > myStack;
		bool isStack = true;

		for (int i =0 ; i < n ; i++)
		{
			if (vec[i].first == 1)
				myStack.push(vec[i].second);
			
			else if (vec[i].first == 2)
			{
				if (myStack.empty() == true)
				{
					isStack = false;
					break;
				}
				
				if (myStack.top() != vec[i].second)
				{
					isStack = false;
					break;
				}
				myStack.pop();
			}
		}

		queue <int> myQueue;
		bool isQueue = true;

		for (int i =0 ; i < n ; i++)
		{
			if (vec[i].first == 1)
				myQueue.push(vec[i].second);
			
			else if (vec[i].first == 2)
			{
				if (myQueue.empty() == true)
				{
					isQueue = false;
					break;
				}
				
				if (myQueue.front() != vec[i].second)
				{
					isQueue = false;
					break;
				}
				myQueue.pop();
			}
		}

		priority_queue <int> myPQ;
		bool isPriority = true;

		for (int i =0 ; i < n ; i++)
		{
			if (vec[i].first == 1)
				myPQ.push(vec[i].second);
			
			else if (vec[i].first == 2)
			{
				if (myPQ.empty() == true)
				{
					isPriority = false;
					break;
				}
				
				if (myPQ.top() != vec[i].second)
				{
					isPriority = false;
					break;
				}
				myPQ.pop();
			}
		}

		int flag = 0;
		if (isStack)
			flag++;
		if (isQueue)
			flag++;
		if (isPriority)
			flag++;

		if (flag == 0)
			cout << "impossible" << endl;
		else if (flag > 1)
			cout << "not sure" << endl;
		else if (isStack)
			cout << "stack" << endl;
		else if (isQueue)
			cout << "queue" << endl;
		else if (isPriority)
			cout << "priority queue" << endl;



	}

	return 0;
}