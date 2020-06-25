#include <bits/stdc++.h>
using namespace std;

struct E{
    string A,B,C;
};

map <string , E> expressions;

string dfs (string val){
    struct E V = expressions[val];
    string ret = "" , left , right;

    if (V.A[0] >= '0' && V.A[0] <= '9') left = V.A;
    else left = dfs (V.A);

    if (V.B[0] >= '0' && V.B[0] <= '9') right = V.B;
    else right = dfs(V.B);

    // cout << left << " " << right << endl;
    if (V.C[0] == '+'){
        ret = left + "+";
        bool flag = false;
        int brackets = 0;

        for (int i =0 ; i < right.size() && !flag ; i++){
            if (right[i] == '(')brackets++;
            if (right[i] == ')')brackets--;
            if (brackets == 0 && right[i] == '+')
                flag = true;
        }
        if (!flag)  ret = ret + right;
        else 
            ret = ret + "(" + right + ")";
        return ret;
    }
    else{
        int brackets = 0;
        bool flag = false;
        for (int i =0 ; i < left.size() && !flag ; i++){
            if (left[i] == '(')brackets++;
            if (left[i] == ')')brackets--;
            if (brackets == 0 && left[i] == '+')
                flag = true;
        }
        if (flag){
            ret = '(' + left + ")*" ;
        }else{
            ret = left + "*";
        }
        brackets = 0;
        flag = false;

        for (int i =0 ; i < right.size() && !flag ; i++){
            if (right[i] == '(')brackets++;
            if (right[i] == ')')brackets--;
            if (brackets == 0 && (right[i] == '+' || right[i] == '*') )
                flag = true;
        }
        if (flag){
            ret = ret + "(" + right + ")";
        }else{
            ret = ret + right;
        }
        return ret;
    }
}


int main (){
    int testcases, expr_no = 0;
    cin >> testcases;
    while(testcases--){
        expr_no++;
        int total;
        expressions.clear();
        cin >> total;
        string s1,tmp,s2,s3,s4;
        while (total--){
            cin >> s1 >> tmp >> s2 >> s3 >> s4;
            struct E expr = {s2,s4,s3};             //left ; right ; operation
            expressions[s1] = expr;
        }
        string ans = dfs(s1);
        cout << "Expression #" << expr_no << ": ";
        cout << ans;
        cout << endl;
    }
}