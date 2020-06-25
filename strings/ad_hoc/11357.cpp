#include <bits/stdc++.h>
using namespace std;

map <char , bool> assign;

bool check_clause(string s){
    assign.clear();
    for (int i= 1 ; i < s.size() - 1 ;){
        
        if (s[i] >= 'a' && s[i] <= 'z'){
            if (assign.find (s[i]) == assign.end()){
                assign[s[i]] = true;
            }else if (assign[s[i]] == false){
                return false;
            }
        }
        else if (s[i] == '~'){
            i++;
            if (assign.find(s[i]) == assign.end()){
                assign[s[i]] = false;
            }
            else if (assign[s[i]] == true){
                return false;
            }
        }
        i++;
    }
    return true;
}

bool check_formula (char* s){
    char *p;
    // cout << s << endl;
    vector <string> clauses;
    for (p = strtok (s , "|") ; p ; p = strtok(NULL , "|")){
        clauses.push_back(p);
    }
    for (int i= 0 ; i < clauses.size() ; i++){
        // cout << "checking " << clauses[i] << endl;
        if (check_clause(clauses[i]))return true;
    }
    return false;
}


int main (){
    int testcases;
    cin >> testcases;
    char temp[10];
    fgets(temp , 10 , stdin);
    while (testcases--){
        assign.clear();
        char s[500];
        fgets(s , 500 , stdin);
        s[strlen(s) - 1] = 0;
        if (check_formula(s)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}