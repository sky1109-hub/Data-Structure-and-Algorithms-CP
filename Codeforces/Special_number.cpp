#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        ll curPower = 1; 

        while (k > 0) {
            if (k & 1)
                ans = (ans + curPower) % mod;

            curPower = (curPower * n) % mod; 
            k >>= 1;  
        }

        cout << ans % mod << "\n";
    }
    return 0;
}
