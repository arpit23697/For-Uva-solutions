#include <bits/stdc++.h>
using namespace std;

int main (){
    int correct =0 ;
    string str;

    while (cin >> str){
        bool add = false;
        vector <int> f,s,t;
        bool first = true, second = false , third = false;
        for (int i= 0 ; i < str.size() ; i++){
            if (str[i] == '+'){
                add = true;
                first = false;
                second = true;
            }
            else if (str[i] == '-'){
                add = false;
                first = false;
                second = true;
            }
            else if (str[i] == '='){
                second = false;
                third = true;
            }
            else {
                if (first){
                    f.push_back(str[i]);
                }else if (second){
                    s.push_back(str[i]);
                }else if (third){
                    t.push_back(str[i]);
                }
            }
        }
        if (t[0] == '?')continue;
        int num1 = 0 , num2 = 0 , num3 = 0;
        for (int i =0 ; i < f.size() ; i++){
            num1 = num1*10 + (f[i] - '0');
        }
        for (int i =0 ; i < s.size() ; i++){
            num2 = num2*10 + (s[i] - '0');
        }
        for  (int i = 0 ; i < t.size() ; i++){
            num3 = num3 * 10 + (t[i] - '0');
        }
        if (add && num1 + num2 == num3){
            correct++;
        }
        else if (!add && num1 - num2 == num3){
            correct++;
        }
    }
    cout << correct << endl;
    return 0;
}