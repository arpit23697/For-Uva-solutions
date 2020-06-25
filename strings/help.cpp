#include <bits/stdc++.h>
using namespace std;

int isvowel (char ch){ //make sure ch is in lower case
    char vowel[6] = "aeiou";
    for (int j = 0 ; vowel[j] ; j++){
        if (vowel[j] == ch){
            return 1;
        }
    }
    return 0;
}


int main (){
    int i , pos , digits , alphas , consonanats , vowels;
    bool first = true , prev_dash , this_dash;
    char str[10010] , line[110] , *p;

    freopen ("ch6.txt" , "r" , stdin);

    strcpy(str , "");
    first = true;
    prev_dash = this_dash = false;
    
    //this is to read the whole paragraph
    while (1){
        fgets (line , 100 , stdin);
        line[(int)strlen(line) - 2] = 0; //delete the dummy character
        if (strncmp(line , "......." , 7) == 0)break;
        if (line[(int)strlen(line ) - 1] == '-'){
            line[(int)strlen(line) - 1] = 0;
            this_dash = true;
        }else{
            this_dash = false;
        }
        if (!first && !prev_dash){
            strcat(str , " ");
        }
        first = false;
        strcat(str , line);
        prev_dash = this_dash;
    }

    for (i = digits = alphas = consonanats = vowels = 0 ; str[i] ; i++){
        str[i] = tolower(str[i]);
        digits += isdigit(str[i]) ? 1 : 0;
        alphas += isalpha(str[i]) ? 1 : 0;
        vowels += isvowel(str[i]) ? 1 : 0;
    }
    consonanats = alphas - vowels;
    printf("%s\n" , str);
    cout << digits << " " << vowels << " " << consonanats << endl;

    int hascs3233 = (strstr(str , "cs3233") != NULL);
    vector <string> tokens;
    map<string , int >freq;

    for (p = strtok (str , " .") ; p ; p = strtok(NULL , " .")){
        // cout << p << endl;
        tokens.push_back(p);
        freq[p]++;
    }

    sort(tokens.begin() , tokens.end());
    cout << tokens[0] << " " << tokens[(int)tokens.size() - 1] << endl;
    printf("%d\n" , hascs3233);

    int ans_s , ans_h , ans_7 = 0;
    char ch;
    while (scanf("%c" , &ch) , ch != '\n'){
        if (ch == 's')ans_s++;
        else if (ch == '7')ans_7++;
        else if (ch == 'h')ans_h++;
    }
    cout << ans_s << " " << ans_7 << " " << ans_h;
    return 0;
}