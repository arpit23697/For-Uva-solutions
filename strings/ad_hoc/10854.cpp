#include <bits/stdc++.h>
using namespace std;

vector <string> program;

int iter = 0;

long long int process_if_else (){
    long long int if_ans = 1;
    long long int else_ans = 1;
    bool inside_if = true;
    
    while (1){
        if (program[iter] == "S"){
            iter++;
        }else if (program[iter] == "IF"){
            iter++;
            if (inside_if){
                if_ans = if_ans * process_if_else();
            }
            else {
                else_ans = else_ans * process_if_else();
            }
        }else if (program[iter] == "ELSE"){
            iter++;
            inside_if = false;
        }
        else if (program[iter] == "END_IF"){
            iter++;
            break;
        }
    }
    return if_ans + else_ans;
}

long long int find_path (){

    long long int ans = 1;
    
    for (; iter < program.size() ; ){
        if (program[iter] == "S"){
            iter++;
            continue;
        }
        else if (program[iter] == "IF"){
            iter++;
            long long int temp = process_if_else();
            // cout << temp  <<  " " << ans << endl;
            ans = ans *temp;
        }
    }
    return ans;
}





int main (){
    int test;
    cin >> test;
    while (test--){
        program.clear();
        iter = 0;
        while (1){
            string s;
            cin >> s;
            if (s == "ENDPROGRAM")break;
            else program.push_back(s);
        }
        cout << find_path() << endl;
    }
}
