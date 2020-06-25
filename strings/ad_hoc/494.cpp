#include <bits/stdc++.h>
using namespace std;

int main (){
    string str;
    while (getline (cin , str)){
        bool word = false;
        int ans = 0;
        for (int i =0 ; i < str.size() ;i++){
            if ( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ){
                if (word)continue;
                else {
                    word = true;
                    ans++;
                }
            }
            else {
                word = false;
            }
        }
        cout << ans << endl;
    }
    return 0;
}