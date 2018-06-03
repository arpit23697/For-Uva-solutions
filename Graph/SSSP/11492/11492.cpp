#include <bits/stdc++.h>
using namespace std;


vector <vector <pair <int ,int>>> graph;
map <string , int> map1;
//map <int , string> map2;
vector <pair <string , string >> lang;
vector <string> words;
int total = 0;

vector <int> dist;
int inf = 10000000;
//vector <int> pre;


void dijekstra (int start)
{
    dist.assign (total , inf);
    dist[start] = 0;

  //  pre.assign (total , -1);
    priority_queue <pair <int , int > , vector <pair <int , int>> , greater <pair <int ,int >>> pq;
    pq.push(make_pair (0 , start));

    while (!pq.empty())
    {
        pair <int , int > p = pq.top();
        pq.pop();

        int u = p.second;
        int d = p.first;

        if (d > dist[u])
        continue;

        for (int i =0 ; i < graph[u].size() ; i++)
        {
            pair <int ,int > v = graph[u][i];
            if (dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair (dist[v.first] , v.first));
    //            pre[v.first] = u;
            }
        }
    }
}



int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
    while (1)
    {
        int m;
        cin >> m;
        if (m == 0)
        break;


        int n = 0;
        map1.clear();
        int edges;
        string str;
        cin >> str;

        pair< map<string, int>::iterator , bool> ret;
        ret = map1.insert (make_pair (str , n));
        if (ret.second == true)
        n++;
        cin >> str;

        map1.insert(make_pair (str , n));
        if (ret.second == true)
        n++;

       
        string x ,y ,z;

        lang.assign (m , make_pair ("" , ""));
        words.assign (m , "");
        for (int i=0 ; i < m ; i++)
        {   
            cin >> x >>y >> z;
            lang[i] = make_pair (x , y);
            words[i] = z;

            ret = map1.insert (make_pair (x , n));
            if (ret.second == true)
                n++;    

            ret = map1.insert (make_pair (y , n));
            if (ret.second == true)
                n++;
    
        }

      //  for (map <string , int> :: iterator itr = map1.begin() ; itr != map1.end() ; ++itr)
      //  cout << itr->first << " " << itr->second << endl;

        total = n*26 + 2;
        graph.assign (total , vector <pair <int ,int >>());
        for (int i = 0 ; i < m ; i++)
        {
            int x , y ,we;
            x = map1[lang[i].first];
            y = map1[lang[i].second];
            we = words[i].size();
           // cout <<  words[i]  <<" " <<we << endl;
            char temp = words[i][0];
            int a = temp-'a';
            int b = a + x*26+1;
            int c = a + y*26+1;
           // cout << temp << " " << a << " " << b << " " <<c << endl;
            
            for (int j = y*26+1 ; j < y*26 + 27 ; j++)
            {
                if (j == c)
                continue;

                graph[b].push_back (make_pair (j, we));
            }
            for (int i= x*26 + 1; i < x*26 + 27 ; i++)
            {
                if (i == b)
                continue;

                graph[c].push_back (make_pair (i ,we));
            }
            
            
            /*for (int i= x*26+1 ; i < x*26+27 ; i++)
            for (int j =y*26+1 ; j < y*26+27 ; j++)
            {
                if (i == b || j == c)
                continue;

                graph[i].push_back (make_pair (j , we));
                graph[j].push_back (make_pair (i , we));
            }*/
        } 

      //  for (int i= 0 ; i < graph[1].size() ; i++)
      //  cout << graph[1][i].first << " " << graph[1][i].second << endl;
        for (int i = 0 ; i < 26 ; i++)
        {
            graph[0].push_back(make_pair (i+1 , 0));
            graph[i+1].push_back (make_pair (0 , 0));
            graph[total-1].push_back(make_pair (i+27 , 0));
            graph[i+27].push_back (make_pair (total - 1 , 0));
        }

        dijekstra (0);

    /*    int current = total - 1;
        cout << "Path is " << endl;

        while (current != -1)
        {
            cout << current << " ";
            current = pre[current];
        }
        cout << endl;
      */  //cout << dist[total - 1] << endl;
        if (dist[total - 1 ] == inf)
            cout << "impossivel" << endl;
        else
            cout << dist[total- 1] << endl;

    }
    
    return 0;
}