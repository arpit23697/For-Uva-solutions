#include <bits/stdc++.h>
using namespace std;

int main (){
   char line[15];
   fgets(line , 100, stdin);  
    unsigned int temp[8] = {128,64,32,16,8,4,2,1};
    while (1){
        fgets(line , 100 , stdin);
        if (line[0] == '_')break;
    
        unsigned short s = 0;
        int j =0;
        for (int i = 1 ; i < strlen(line) - 1 ;i++){
            if (line[i] == 'o'){
                s = s + temp[j];
                j++;
            }
            else if (line[i] == ' ')j++;
        }
        char c = s;
        cout << c;    
    }
}