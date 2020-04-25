#include <bits/stdc++.h>
using namespace std;

int main (){
    int test;
    unsigned int power_2s[8] = {1,2,4,8,16,32,64,128};
    
    cin >> test;

    for (int t = 0 ; t < test ; t++){
        vector <string> msg;
        for (int i =0 ; i < 10; i++){
            string s;
            cin >> s;
            msg.push_back(s);
        }
        int m = (int)msg[0].size();

        for (int j = 1 ; j < m-1 ; j++){
            unsigned int temp = 0;
            for (int i = 1 ; i < 9 ; i++){
                if (msg[i][j] == '\\'){
                    temp += power_2s[i-1];
                }
            }
            char c = temp;
            cout << c;
        }


        if (t < test - 1){
            char s[100];
            fgets (s , 10 , stdin);
        }
        cout << endl;
    }
    return 0;
}