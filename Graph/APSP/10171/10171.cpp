#include <bits/stdc++.h>
using namespace std;
map <char , int > myMap1;
map <int , char > myMap2;
vector <vector <int> , bool > graph;
int edges ;
int vertices;

int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        graph.clear();
        graph.assign (26 , vector <int > ());
        memset (young , false , sizeof young );
        vertices = 0;

        cin >> edges;
        for (int i= 0 ; i < edges ; i++)
        {
            bool young ;
            char temp ;
            cin >> temp;
            if (temp == 'Y')
            young = true;
            else 
            yound = false;

            cin >> temp;
            char x , y;
            cin >> x;
            cin >> y;
            pair <map <char , int > :: iterator , bool > ret;
	        
            ret = myMap1.insert (make_pair (x , vertices));
            if (ret.second == true)
		    vertices++;

            ret = myMap1.insert (make_pair (y , vertices));
            if (ret.second == true)
            vertices++;

    }
    }
    return 0;
}