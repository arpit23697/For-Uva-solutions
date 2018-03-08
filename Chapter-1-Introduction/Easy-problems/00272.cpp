#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string phrase;
	bool temp = true;

	while (getline (cin , phrase))
	{
		for (int i =0 ; i < phrase.length() ; ++i)
		{
			if (phrase[i] == '"')
				if (temp)
				{
					phrase.replace(i , 1 , "``");
					temp = false;
				}
				else
				{
					phrase.replace(i , 1 , "''");
					temp = true;
				}
		}

		cout << phrase << endl;
	}	

	return 0;

}
