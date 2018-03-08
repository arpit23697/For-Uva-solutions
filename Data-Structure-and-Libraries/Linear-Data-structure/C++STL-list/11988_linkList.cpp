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

using namespace std;

struct node
{
	char data;
	struct node * next;
};

void printLinkList (struct node * head)
{
	struct node * current = (struct node *)malloc (sizeof(struct node));
	current = head;

	while (current != NULL)
	{
		//cout << "hi ";
		if (current -> data != ' ')
			cout << current -> data;
		current = current -> next;
	}


}

void addAtHead ( struct node ** head , char value , long long int counter)
{
	
	struct node * temp = (struct node *)malloc (sizeof (struct node));
	temp -> data = value;

	if (counter == 0)
	{
		
		temp -> next = (*head);
		(*head) = temp;
	}

	else
	{
		counter --;
		struct node *current = (*head);
		for (int i =0; i < counter ; i++)
			current = current -> next;

		temp -> next = current -> next;
		current -> next = temp;

	}

}

void addAtTale (struct node ** head , char value)
{
	
	struct node *temp = (struct node *) malloc (sizeof (struct node));
	temp -> data = value;

	struct node *tale = (*head);

	while (tale -> next != NULL)
		tale = tale -> next;

	tale -> next = temp;
	tale = temp;
	tale -> next = NULL;
}

int main ()
{
	string str;

	while (getline (cin , str))
	{
		struct node * head = (struct node *)malloc (sizeof (struct node));
		head -> data = ' ';
		head -> next = NULL;
		bool addlast = true;

		long long int counter = 0;
		
		for (int i =0 ; i < str.size() ; i++)
		{
			
			if (str[i] == '[')
			{	
				addlast = false;
				counter = 0;
			}
			else if (str[i] == ']')
			{
				counter = 0;
				addlast = true;	
			}
		
			else
				if (addlast == true)
				{	
					counter = 0;
					addAtTale(&head , str[i]);
				}
				else
				{
					
					addAtHead(&head , str[i] , counter);
					counter++;
				}

		
		}
		
		printLinkList (head);
		cout << endl;
	}

	return 0;
}