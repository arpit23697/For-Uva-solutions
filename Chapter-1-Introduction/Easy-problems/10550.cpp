#include <iostream>
#include <string>

using namespace std;

int main ()
{
	while (1)
	{
	int a , b , c ,d ;
	int degrees = 0;

	
	cin >> a >> b >> c >> d ;

	if (a == 0 && b == 0 && c ==0 && d ==0)
		return 0;


	int temp = 0;
	if (b > a)
		temp += 40 - (b-a);

	else
		temp += a-b;

	if (c > b)
		temp += c-b;

	else 
		temp += 40 - (b-c);

	if (d > c)
		temp += 40 - (d - c);
	else
		temp += c-d;

	cout << temp * 9 + 1080 << endl; 
}

return 0;
}