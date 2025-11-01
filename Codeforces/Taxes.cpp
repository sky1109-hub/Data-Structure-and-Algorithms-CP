#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll largestPrimeDivisor(ll n) {
    ll largest = -1;

    
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }


    if (n > 1) largest = n;
    if(largest==n) largest=1;

    return largest;
}

int main() {
    ll n;
    cin >> n;
    cout << largestPrimeDivisor(n) << "\n";
    return 0;
}
