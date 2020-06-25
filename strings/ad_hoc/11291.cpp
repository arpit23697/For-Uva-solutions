#include <bits/stdc++.h>
using namespace std;


double process_string(string s){

    if (s[0] == '('){
        int i = 1;
        for (; i < s.size() ; i++){
            if ( s[i] == ' ' )break;
        }
        // cout << i << endl;
        string str = s.substr(1 , i-1);
        double p = stod (str);
        double n1 = 0 , n2 = 0;
        i++;
        
        // process e1
        if (s[i] == '('){
            int brackets = 0;
            string temp = "";
            for ( ; i < s.size() ; i++){
                if (s[i] == '(')brackets++;
                if (s[i] == ')')brackets--;
                temp = temp + s[i];
                if (s[i] == ')' && brackets == 0){
                    i++;
                    break;
                }
                
            }
            // cout << temp << "tempp" << endl;
            n1 = process_string(temp);
        }else {
            string temp = "";
            for ( ; i < s.size() ; i++){
                if(s[i] == ' '){
                    break;
                }
                temp = temp + s[i];
            }
        //    cout <<"n1 " << temp << "j" << endl;
            n1 = stod (temp);
        }   

        //process e2
        i++;
        if (s[i] == '('){
            string temp = "";
            int brackets= 0;
            for ( ; i < s.size() ; i++){
                if (s[i] == '(')brackets++;
                if (s[i] == ')')brackets--;
                temp = temp + s[i];
                if (s[i] == ')' && brackets == 0){
                    i++;
                    break;
                }
            }
            n2 = process_string(temp);
        }else {
            string temp = "";
            for ( ; i < s.size() ; i++){

                if(s[i] == ' ' || s[i] == ')' ){
                    break;
                }
                temp = temp + s[i];
            }
            // cout << "n2 " << temp << "j" << endl;
            n2 = stod (temp);
        }

            // cout << p << " " << n1 << " " << n2 << endl;
            double ans = p * (n1+n2) + (1-p) * (n1-n2); 
            return ans;
        



    
    }else{
        double n = 0;
        int i =0 ;
        bool neg = false;
        if (s[i] == '-'){
            i++;
            neg = true;
        }
        for (; i < s.size() ; i++){
            if (s[i] >= '0' && s[i] <= '9'){
                n = n * 10 + (s[i] - '0');
            }else break;
        }
        if (neg)return -n;
        return n;
    }
}

int main (){
    while (1){
        string s;
        getline(cin,s);
        if (s == "()")break;
        // cout << "Hi there : ";
        // cout <<  s << endl;
        double ans = process_string(s);
        printf("%0.2lf\n" , ans);
    }
    return 0;
}