#include <bits/stdc++.h>
using namespace std;

map <long long int , int> fib;
void fibonacci (){
    long long int first = 1 , second = 2;
    fib[first] = 0;
    fib[second] = 1;
    for (int i =2 ; i <= 100 ; i++){
        long long int temp = first + second;
        first = second;
        second = temp;
        fib[second] = i;
    }
}

int main (){
    fibonacci();
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector <long long int > key(n);
        for (int i= 0 ; i < n ; i++) cin >> key[i];

        char str[110];
        fgets (str , 110 , stdin);
        fgets (str , 110 , stdin); 
        vector <char> cipher;
        for (int i = 0; str[i] ; i++){
            if (str[i] >= 'A' && str[i] <= 'Z'){
                cipher.push_back(str[i]);
            }
        }

        vector <char> answer(100 , ' ');
        int largest = 0;
        for (int i = 0 ; i < n ; i++){
            answer[fib[key[i]]] = cipher[i];
            largest = max(largest , fib[key[i]]);
        }
        for (int i= 0 ; i <= largest ; i++)cout << answer[i];
        cout << endl;
    }
    return 0;
}