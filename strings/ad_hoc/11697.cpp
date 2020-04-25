#include <bits/stdc++.h>
using namespace std;

char key[5][5];
vector <string> digrams;


void contruct_key (char *key_phrase){
    vector <bool> used(30 , false);
    memset(key , ' ' , sizeof(key));
    int counter = 0;

    for (int i= 0 ; key_phrase[i] ; i++){
        if (key_phrase[i] >= 'a' && key_phrase[i] <= 'z'){
            if (!used[key_phrase[i] - 'a']){
                used[key_phrase[i] - 'a'] = true;

                int row = counter/5;
                int col = counter%5;

                key[row][col] = key_phrase[i];
                counter+=1;
            }
        }
    }
    for (int i =0 ; i < 26 ; i++){
        if (i != 'q' - 'a' && used[i] == false){
            int row = counter/5;
            int col = counter%5;

            key[row][col] = i + 'a';
            counter+=1;
        }
    }
}

void construct_digrams (char *text){
    digrams.clear();
    vector <char> plain;
    for (int i =0 ; text[i] ; i++){
        if (text[i] >= 'a' && text[i] <= 'z'){
            plain.push_back(text[i]);
        }
    }

    for (int i= 0 ; i < plain.size() ; i++){

        if (i+1 >= plain.size()){
            string str = "";
            str =  plain[i];
            str += 'x';
            digrams.push_back(str);
        }

        else if (plain[i] == plain[i+1]){
            string str = "";
            str = plain[i];
            str += 'x';
            digrams.push_back(str);
        }
        else{
            string str = "";
            str = plain[i];
            str += plain[i+1];
            digrams.push_back(str);
            i++;
        }
        
    }
}

string encrypt_digrams (string str){
    int row1 = -1, col1 = -1 , row2 = -1 , col2 = -1;
    bool found = false;
    for (int i= 0 ; i < 5 ; i++){
        for (int j =0 ; j < 5 ; j++){
            if (key[i][j] == str[0]){
                found = true;
                row1 = i;
                col1 = j;
                break;
            }
        }
        if (found)break;
    }

    found = false;
    for (int i= 0 ; i < 5 ; i++){
        for (int j =0 ; j < 5 ;j++){
            if (key[i][j] == str[1]){
                found = true;
                row2 = i;
                col2 = j;
                break;
            }
        }
        if (found) break;
    }
    string en = "  ";
    if (row1 == row2){
        en[0] = key[row1][ (col1 + 1)%5 ] - 'a' + 'A';
        en[1] = key[row1][ (col2 + 1)%5 ] - 'a' + 'A';
    }
    else if (col1 == col2){
        en[0] = key[ (row1 + 1) % 5 ][col1] - 'a' + 'A';
        en[1] = key[ (row2 + 1) % 5 ][col1] - 'a' + 'A';
    }
    else{
        en[0] = key[row1][col2] - 'a' + 'A';
        en[1] = key[row2][col1] - 'a' + 'A';
    }
    return en;




}

int main (){
    int test;
    char temp[1024];
    cin >> test;
    fgets (temp , 1024 , stdin);
    
    while (test--){
        char key_phrase[1024];
        fgets (key_phrase , 1024 , stdin);
        key_phrase[strlen(key_phrase) - 1] = 0;
        // cout << key_phrase << endl;
        contruct_key(key_phrase);

        char text[1100];
        fgets (text , 1100 , stdin);
        if (text[strlen(text) - 1] == '\n')
            text[strlen(text) - 1] = 0;

        construct_digrams(text);
        for (int i= 0 ; i < digrams.size() ; i++){
            cout << encrypt_digrams(digrams[i]);
        }
        cout << endl;
    }
    return 0;
}