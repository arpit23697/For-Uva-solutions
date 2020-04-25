#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;
    string str;
    while (cin >> n){
        cin >> str;
        map <string , int> freq;
        for (int i= 0; i <= str.size() - n ; i++){
            string temp = "";
            for (int j = i ; j < i + n ; j++){
                temp += str[j];
            }
            freq[temp] += 1;
        }

        string ans = "";
        int most = 0;
        for (auto &x : freq){
            // cout << x.first << "  " << x.second << endl;
            if (x.second >= most){
                most = x.second;
                ans = x.first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}