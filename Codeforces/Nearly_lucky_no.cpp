#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; 
    cin >> n;
    
    ll c = 0; 
    string s = to_string(n);
    
    for(char x : s) {
        if(x == '4' || x == '7')  
            c++;
    }
    
    string k = to_string(c);
    
    for(char it : k) {
        
        if(it != '4' && it != '7') {
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES";
    return 0;
}
