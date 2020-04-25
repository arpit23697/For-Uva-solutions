#include <bits/stdc++.h>
using namespace std;

char shift_k (char c , int k){
    int original = -1;
    if (c >= 'A' && c <= 'Z'){
        original = c - 'A' + 1;
    }else{
        original = 0;
    }
    int new_c = (original + k) % 27;
    if (new_c == 0){
        return ' ';
    } else{
        return 'A' + new_c - 1;
    }
}

int main (){
    set <string> dictionary;
    while (1){
        string str;
        cin >> str;
        if (str == "#")break;
        else dictionary.insert(str);
    }

    char cipher[300];
    fgets(cipher , 300 , stdin);
    fgets (cipher , 300 , stdin);
    cipher[strlen(cipher) - 1] = 0;

    char decipher[300];
    int ans_key = 0;
    int max_match = -1;


    for (int key = 0 ; key <= 27 ; key++){
        for (int i =0 ; cipher[i] ; i++){
            decipher[i] = shift_k(cipher[i] , key);
        }
        decipher[strlen(cipher)] = 0;
        // cout << decipher << endl;
        char *p;
        vector <string> tokens;
        for (p = strtok(decipher , " ") ; p ; p = strtok(NULL , " ")){
            tokens.push_back(p);
        } 
        int total_in_dic = 0;
        for (int i= 0 ; i < tokens.size() ; i++){
            if (dictionary.find(tokens[i]) != dictionary.end()){
                total_in_dic++;
            }
        }
        if (total_in_dic >= max_match){
            ans_key = key;
            max_match = total_in_dic;
        }
    }
    string ans = "";
    for (int i =0 ; cipher[i] ; i++){
        ans  =  ans + shift_k(cipher[i] , ans_key);
    }

    // decipher[strlen(cipher)] = 0;
    // cout << ans << endl;

    int i, l, soFar = 0;
	string bef = "";
	
	for (i = 0; i < ans.length(); i += l+1){
		for (l = 1; i+l < ans.length() && ans[i+l] != ' '; l++);
		
		if (soFar + l + bef.length() > 60){
			cout << '\n';
			bef = "";
			soFar = 0;
		}
		
		soFar += l + bef.length();
		cout << bef << ans.substr(i, l);
		bef = " ";
	}
	
	cout << '\n';


    // char *p;
    // vector <string> tokens;
    // for (p = strtok(decipher , " ") ; p ; p = strtok(NULL , " ")){
    //     tokens.push_back(p);
    // }
    // int total_len = 0;
    // for (int i =0 ; i < tokens.size() ; i++){
        // 
        // if ( i < tokens.size() - 1  && total_len  + tokens[i].size() + 1  <= 60){
            // cout << tokens[i] << " ";
            // total_len += tokens[i].size() + 1;
        // }else if (total_len  + tokens[i].size()  <= 60){
            // cout << tokens[i] << endl;
            // total_len += tokens[i].size();
        // }
        // else{
            // cout << endl;
            // total_len = 0;
        // }
    // }
    // cout << endl;
    return 0;

}