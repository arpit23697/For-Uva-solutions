#include <bits/stdc++.h>
using namespace std;

int main (){
    string a, b;
    while (getline(cin , a)){
        getline(cin , b);
        vector <int> freq_a(26 , 0);
        vector <int> freq_b(26 , 0);
        for (int i= 0; i < a.size() ; i++){
            freq_a[a[i] - 'a']+=1;
        }
        for (int i = 0 ; i < b.size() ; i++){
            freq_b[b[i] - 'a']+=1;
        }
        for (int i = 0 ; i < 26 ; i++){
            int temp = min(freq_a[i] , freq_b[i]);
            char c = 'a' + i;
            while (temp--){
                cout << c ; 
            }
        }
        cout << endl;
    }
    return 0;
}