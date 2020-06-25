#include <bits/stdc++.h>
using namespace std;

bool error = false;

long long int check_factor (string s);
long long int check_component (string s);
long long int check_expression (string s);



int main (){
    int testcases;
    cin >> testcases;
    while (testcases--){
        string s;
        cin >> s;
        error = false;
        long long int ans = check_expression(s);
        if (error)cout << "ERROR" << endl;
        else 
        cout << ans << endl;
    }
}

long long int check_factor (string s){
    if (s.size() == 0){
        error = true;
        return -1000;
    }
    if (s[0] == '(' && s[s.size() - 1] == ')'){
        string str = s.substr(1 , s.size() - 2);
        return check_expression(str);
    }else {
        // cout << s << endl;
        for (int i= 0 ; i < s.size() ; i++){
            if (s[i] >= '0' && s[i] <= '9'){
                continue;
            }
            else {
                error = true;
                return -1000;
            }
        }
        return stoll (s);
    }
}

long long int check_component (string s){
    int brackets = 0 , flag = -1;
    for (int i= 0; i < s.size() ; i++){
        if (s[i] == '(')brackets++;
        else if (s[i] == ')')brackets--;
        if (s[i] == '*' && brackets ==0){
            flag = i;
            break;
        }
    }
   if (flag == -1){
       return check_factor(s);
    }else{
        string left = s.substr(0, flag);
        string right = s.substr(flag+1 , s.size() - flag - 1);
        long long int n = check_factor(left) * check_component(right);
        return n;
    }
}

long long int check_expression (string s){
    //checking for plus
    int brackets = 0 , flag = -1;
    for (int i= 0; i < s.size() ; i++){
        if (s[i] == '(')brackets++;
        else if (s[i] == ')')brackets--;
        if (s[i] == '+' && brackets ==0){
            flag = i;
            break;
        }
    }
    if (flag == -1){
        return check_component(s);
    }
    else{
        string left = s.substr(0, flag);
        string right = s.substr(flag+1 , s.size() - flag - 1);
        // cout << left << " " << right << endl;
        long long int n1 = check_component(left) + check_expression(right);
        return n1;
    }
}
