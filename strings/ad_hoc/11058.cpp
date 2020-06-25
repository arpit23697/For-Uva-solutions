#include <bits/stdc++.h>
using namespace std;

bool error = false;
vector <string> article = {"a" , "the"};
vector <string> noun = {"tom" , "jerry" , "goofy" , "mickey" , "jimmy" , "dog" , "cat" , "mouse"};
vector <string> verb = {"hates" , "loves" , "knows" , "likes" , "hate" , "love" , "know" , "like"};
void process_string (string s);
void process_action (string s); 
void process_active_list (string s);
void process_actor (string s);

string ltrim(const string& s) {
	return regex_replace(s, regex("^\\s+"), string(""));
}

string rtrim(const string& s) {
	return regex_replace(s, regex("\\s+$"), string(""));
}

string trim(const string& s) {
	return ltrim(rtrim(s));
}


int main (){
    string line;


    while (getline(cin , line)){
        error = false;
        process_string (line);
        if (error){
            cout << "NO I WON'T" << endl;
        }else {
            cout << "YES I WILL" << endl;
        }
    }
    return 0;
}

void process_actor (string s){
    s = trim (s);
    istringstream ss(s);
    vector <string> words;
    string word;
    while (ss >> word){
        words.push_back(word);
    }

    
    if (words.size() == 1){
        bool find = false;
        for (int i =0 ; i < noun.size() ;i++){
            if (noun[i] == words[0]){
                find = true;
                break;
            }
        }
        if (!find) error = true;
    }
    else if (words.size() == 2){
        if ( !(words[0] == "a" || words[0] == "the") )error = true;
        bool find = false;
        for (int i =0 ; i < noun.size() ;i++){
            if (noun[i] == words[1]){
                find = true;
                break;
            }
        }
        if (!find) error = true;   
    }
    else error = true;
}


void process_active_list (string s){
    s = trim(s);
    // cout << s << endl;
    string delimiter = "and";
    int pos = 0;
    string token;
    bool pushed = false;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);        
        s.erase(0, pos + delimiter.length());
        process_actor(token);
        pushed = true;
    }
    if(!pushed)process_actor(s);

}

void process_action (string s){
    s = trim(s);
    //split using verbs
    // cout << s << endl;
    bool done = false;
    for (int i =0 ; i < verb.size() ; i++){
        int pos = 0;

        if ((pos = s.find(verb[i])) != std::string::npos){
            string s1 = s.substr (0 , pos);
            s.erase(0, pos + verb[i].length());

            process_active_list(s1);
            process_active_list(s);

            done = true;
            break;
        }
    }
    if (!done){
        error = true;
    }

}

void process_string (string s){
    string delimiter = ",";
    int pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);        
        s.erase(0, pos + delimiter.length());
        process_action(token);
    }
    process_action(s);
}