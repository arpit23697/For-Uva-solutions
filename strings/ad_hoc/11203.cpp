#include <bits/stdc++.h>
using namespace std;



int main (){
    int test;
    cin >> test;
    while (test--){
        string str ;
        cin >> str;
        int first = 0, second = 0 , third = 0;
        bool f , s , t = false;
        f = true;
        bool ans = true;

        for (int i= 0; i < str.size() ; i++){
            if (str[i] == '?' || str[i] == 'M' || str[i] == 'E'){
                if (str[i] == '?' && f){
                    first++;
                }
                else if (str[i] == '?' && s){
                    second++;
                }
                else if (str[i] == '?' && t){
                    third++;
                }
                else if (str[i] == 'M'){
                    if (f){
                        f = false;
                        s = true;
                    }
                    else {
                        ans = false;
                        break;
                    }
                }
                else if (str[i] == 'E'){
                    if (s){
                        s = false;
                        t = true;
                    }else{
                        ans = false;
                        break;
                    }
                }
            }
            else{
                ans = false;
                break;
            }
        }
        // cout << first << " " << second << " " << third << endl;
        if (!ans){
            cout << "no-theorem" << endl;
            continue;
        }
        if (third - first == second && first >= 1 && second >= 1 ){
            cout << "theorem" << endl;
        }
        else {
            cout << "no-theorem" << endl;
        }
    }
    return 0;
}