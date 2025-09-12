#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sumPath(ll n) { 
    ll sum = 0;
    while (n >= 1) {
        sum += n;  
        n /= 2; 
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;  
        cout << sumPath(x) << '\n';
    }
    return 0;
}
