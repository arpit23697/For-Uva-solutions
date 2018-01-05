#include <stdio.h>
#include <vector>
#include <iterator>
#include <algorithm>


using namespace std;
bool any (int weeks , int *a , int participants)
{
	for (int i =0 ; i < weeks ; i++)
	{
		if (a[i] >= participants)
			return true;
	}
	return false;
}

int main ()
{
	int participants , budget , hotels , weeks;
	while (scanf("%d %d %d %d",&participants , &budget , &hotels , &weeks ) == 4)
	{
		int currentBudget = 0;
		while (hotels--)
		{
			int price;
			int W[weeks];

			scanf("%d" , &price);
			for (int i =0 ; i < weeks ; i++)
			{
				scanf("%d",&W[i]);
			}

			if (any (weeks , W , participants))
			{
				if (currentBudget == 0)
				{
					currentBudget = price * participants;
				}

				if (price * participants < currentBudget)
					currentBudget = price * participants;
			}

		}

		if (currentBudget == 0 || currentBudget > budget)
			printf("stay home\n");
		else
			printf("%d\n",currentBudget);
	}
	return 0;
}