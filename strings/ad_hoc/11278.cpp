#include <bits/stdc++.h>
using namespace std;


string Qwerty = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
string Dvorak = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' ~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

int main (){
    map <char , char > decode;
    for (int i =0 ; i < Qwerty.size() ; i++){
        decode[Qwerty[i]] = Dvorak[i];
    }

    string str;
    while(getline(cin , str)){
        for (int i =0 ; i < str.size() ; i++){
            cout << decode[str[i]];
        }
        cout << endl;
    }
    return 0;
}