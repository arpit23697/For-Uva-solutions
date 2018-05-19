#include <bits/stdc++.h>
using namespace std;

int graph[500][500];
int s = 0;
int n , t;
int total;
int m;          //this is the maximum capacity in a given unit of time
vector <int> pre;
int inf = 1000000;
int flow , maxFlow;

vector<pair<int, pair<int, int>>> monkeys;
vector<int> junctions;

void augment (int v , int minEdge)
{
    if (v == s)
    {
        flow = minEdge;
        return;
    }
    else if (pre[v] != -1)
    {
        augment (pre[v] , min (minEdge , graph[pre[v]][v]));
        graph[pre[v]][v] -= flow;
        graph[v][pre[v]] += flow;
    }
}




int binarySearch (int l , int r , int value)
{
    //for (int i = 0; i < junctions.size(); i++)
      //  cout << junctions[i] << endl;

    //cout << "hi " << endl;

    //cout << l << " " << r <<endl;
 if (l > r)
    return -1;

    int mid = l + (r-l)/2;
    if (junctions[mid] == value)
    return mid;

    else if (junctions[mid] > value)
    return binarySearch (l , mid-1 , value);

    else
    return binarySearch (mid+1 , r , value);

}




int main ()
{
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);

    int cases =0 ;
    while (1)
    {
        cases++;
        cin >> n;
        if (n == 0)
        break;

        cin >> m;
        set<int> mySet;                 //this is just to split the interval
        monkeys.clear();
        junctions.clear();

        int totalThirst = 0;


        //cout << n << " " << m << endl;
        for (int i= 0 ; i < n ; i++)
        {
            int v , a,  b;
            
           // cout << "totalThirst  " << totalThirst << endl;

            cin >> v >> a >>b;
            totalThirst += v;
            monkeys.push_back (make_pair (v , make_pair(a , b)));
            mySet.insert (a);
            mySet.insert (b);
        }
                //for (int i= 0 ; i < n ; i++)
        //cout << monkeys[i].first << " " << monkeys[i].second.first << " " << monkeys[i].second.second << endl;
        //for (set <int> :: iterator itr = mySet.begin() ; itr != mySet.end() ; ++itr)
          //   cout << *(itr) << endl;

        map < pair <int , int > , int > intervals;
        map <int , pair <int , int >> intervals2;
 
        for (set <int> :: iterator itr = mySet.begin() ; itr != mySet.end() ; ++itr)
        junctions.push_back (*itr);
    
      //  for (int i= 0 ; i < junctions.size() ; i++)
      //  cout << junctions[i] << endl;

        for (int i = 1 ; i < junctions.size() ; i++)
        {
            intervals.insert (make_pair (make_pair ( junctions[i-1] , junctions[i]) ,i-1 ) );
            intervals2.insert (make_pair (i-1 , make_pair (junctions[i-1] , junctions[i])) );
        }
       // for (map<pair<int, int>, int> :: iterator itr = intervals.begin() ; itr != intervals.end() ; ++itr)
         //   cout << itr->first.first << " " << itr->first.second << " " << itr->second << endl; 
        int numberOfintervals = intervals.size();
        total = numberOfintervals + n + 2;                                //this is to store the total graph size
        s = 0;
        t = total-1;

      //  cout << total << " " <<s << " " << t <<" " << n  << " " << numberOfintervals<< endl;

        for (int i = 0; i < total ; i++)
        for (int j =0 ; j < total ; j++)
        graph[i][j] = 0;


        //setting for the source
        for (int i=1 ; i <= n ; i++)
        graph[s][i] = monkeys[i-1].first;

        //setting for the 
        for (int i =0 ; i < numberOfintervals ; i++)
        graph[i+n+1][t] = m * (junctions[i+1] - junctions[i]);
/*
        for (int i=0 ; i < total ; i++)
        {
            for (int j =0 ; j < total ; j++)
            cout << graph[i][j] << " ";
            cout << endl;
        }
  */
        //setting the edges between the monkey and the interval
        // this is going to done for each monkey
        for (int i= 0 ; i < n ; i++)
        {
            int we = monkeys[i].first;
            int a = monkeys[i].second.first;
            int b = monkeys[i].second.second;

            //cout << a << " " << endl;
            int index1 = binarySearch (0 , numberOfintervals , a);
            int index2 = binarySearch (0 , numberOfintervals , b);

        //   cout << a << " " << index1 << endl;
        //   cout << b << " " << index2 << endl;

            for (int j = index1 ; j < index2 ; j++)
            {
                int x = intervals[make_pair (junctions[j] , junctions[j+1])];
               // cout << x << endl;
                graph[i+1][n+x+1] = min (junctions[j+1] - junctions[j] , we);
            }
        }

        /*
        for (int i=0 ; i < total ; i++)
        {
            for (int j =0 ; j < total ; j++)
            cout << graph[i][j] << " ";
            cout << endl;
        }*/
  

        //applying the max flow algorithm
        maxFlow = 0;
        while (1)
        {
            flow = 0;
            vector <int> dist;
            dist.assign (total , inf);
            dist[s] = 0;

            pre.assign (total , -1);
            queue <int> q;
            q.push (s);

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                if (u == t)
                break;

                for (int v= 0 ; v < total ; v++)
                {
                    if (graph[u][v] > 0 && dist[v] == inf)
                    {
                        q.push(v);
                        dist[v] = dist[u] + 1;
                        pre[v] = u;
                    }
                }
            }
            augment (t , inf);
            if (flow == 0)
            break;
            maxFlow += flow;
        }
   //     cout << totalThirst << " " << maxFlow << endl;
     //  for (map <int , pair <int , int >> :: iterator itr = intervals2.begin(); itr != intervals2.end() ; ++itr)
     //   cout << itr->first << " " << itr->second.first << " " << itr->second.second << endl;

        /*
        for (int i=0 ; i < total ; i++)
        {
            for (int j =0 ; j < total ; j++)
            cout << graph[i][j] << " ";
            cout << endl;
        }*/

        int marker[numberOfintervals];
        for (int i =0 ; i < numberOfintervals ; i++)
        marker[i] = junctions[i];

        if (totalThirst != maxFlow )
            printf("Case %d: No\n", cases);
        else
        {
            printf("Case %d: Yes\n", cases);
            vector <pair <int , int >> ans;
            //this is for each monkey
            for (int i = 0 ; i < n ; i++)
            {
                ans.clear();
                for (int j =0 ; j < numberOfintervals ; j++)
                {
                    pair <int , int > p = intervals2[j];
                    int x = graph[j + n + 1][i + 1];
                    if (x > 0)
                    {   
                        if (x == p.second - p.first)
                        ans.push_back (p);
                        else
                        {
                            if (p.second-marker[j] == x)
                            {
                                ans.push_back(make_pair(marker[j] , p.second));
                                marker[j] = junctions[j];
                            }
                            else if (p.second - marker[j] > x)
                            {
                                ans.push_back (make_pair (marker[j] , marker[j] + x));
                                marker[j] = marker[j]+x;
                            }
                            else
                            {
                                ans.push_back (make_pair (marker[j] , p.second));
                                x -= p.second - marker[j];
                                ans.push_back (make_pair (junctions[j] , junctions[j] + x));
                                marker[j] = junctions[j] + x;
                            }
                        }
                    }
                }
                //for (int i= 0 ; i < ans.size() ; i++)
                //cout << ans[i].first << " " << ans[i].second << endl;
                vector <pair <int , int >> realAns;
                int n2 = 0;
                realAns.push_back(ans[0]);

                for (int i =1 ; i < ans.size() ; i++)
                {
                    if (realAns[n2].second == ans[i].first)
                    {
                        pair <int , int> p = realAns[n2];
                        p = make_pair (p.first , ans[i].second);
                        realAns[n2] = p;
                    }
                    else
                    {
                        n2++;
                        realAns.push_back(ans[i]);
                    }
                }
                //for (int j = 0; j < ans.size(); j++)
                   // cout << " (" << ans[j].first << "," << ans[j].second << ")";
                   // cout <<endl <<  "=======================" << endl;

                sort (realAns.begin() , realAns.end());
                vector <pair <int, int>>realAns2;
                realAns2.push_back (realAns[0]);

                n2 =0 ;
                for (int i= 1 ; i < realAns.size() ; i++)
                {
                    if (realAns2[n2].second == realAns[i].first )
                    {
                        pair <int , int > p = realAns2[n2];
                        p = make_pair (p.first , realAns[i].second);
                        realAns2[n2] = p;
                    }
                    else
                    {
                        n2++;
                        realAns2.push_back(realAns[i]);
                    }
                }


                cout << realAns2.size();
                for (int j = 0 ; j < realAns2.size() ; j++)
                cout << " (" << realAns2[j].first << "," << realAns2[j].second << ")";

                cout << endl;
            }
        }
    }
    return 0;
}