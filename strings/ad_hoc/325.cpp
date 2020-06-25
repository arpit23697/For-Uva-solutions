#include <bits/stdc++.h>
using namespace std;


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
    while (1){
        string str;
        getline(cin , str);
        str = trim(str);
        if (str == "*")break;

        regex r1("([+-]?)([0-9]+)(\\.([0-9]+))([eE][+-]?[0-9]+)?");
        regex r2("([+-]?)([0-9]+)(\\.([0-9]+))?([eE][+-]?[0-9]+)");

        if ( regex_match(str, r1) || (regex_match(str , r2)) ){
            cout << str << " is legal." << endl; 
        }else{
            cout << str << " is illegal." << endl;
        }
    }
    return 0;
}