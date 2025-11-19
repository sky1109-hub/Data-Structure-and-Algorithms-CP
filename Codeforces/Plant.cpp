#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

// fast power
ll power(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return r;
} 

int main() {
    ll n;
    cin >> n;

    ll p4 = power(4, n);
    ll p2 = power(2, n);

    ll ans = (p4 + p2) % MOD;
    ans = (ans * ((MOD + 1) / 2)) % MOD;  // divide by 2

    cout << ans << "\n";
    return 0;
}

