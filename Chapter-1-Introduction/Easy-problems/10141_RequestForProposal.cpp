#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int main ()
{
	int proposals ;
	int requirements;
	int cases=1;

	cin >> requirements >> proposals ;
	while (1)
	{

		string currentCompany;
		currentCompany = "";


		double currentPrice = 20000000000;
		int requirementMet = 0;


		//taking the requirements
		string temp;
		for (int i =0 ; i < requirements ; i++)
		{
				cin.ignore();
				getline (cin , temp);
				   

				 //cout << "hi there " << i << endl;
				//cout << temp;
		}

		for (int k = 0; k < proposals ; k++)
		{
			string company ;
			//cin.ignore();
			getline (cin , company);
			   

			//cout << company << endl;

			double price ;
			int requirementsGiven ;
			cin >> price >> requirementsGiven;

			if (currentCompany == "")
				currentCompany = company;

			

			for (int i =0 ; i < requirementsGiven ; i++)
			{
				cin.ignore();
				getline (cin , temp);	
				
				//cout << "Hi there regd " << i << endl; 
			}
				

			if (requirementsGiven > requirementMet)
			{
				//cout << "hii\n";


				requirementMet = requirementsGiven;
				currentCompany = company;
				currentPrice = price;
			}

			else if (requirementsGiven == requirementMet)
			{
				if (currentPrice > price)
				{
					//cout << "hi\n"; 
					requirementMet = requirementsGiven;
					currentCompany = company;
					currentPrice = price;
				}
			}

			//cout << currentCompany << endl;
		}

		cout << "RFP #" << cases << endl;
		cout << currentCompany << endl;



		cases++;



	
		cin >> requirements >> proposals ;
		if (requirements == 0 && proposals == 0)
			break;
		
		else
			cout << endl;
	}

	return 0;
}