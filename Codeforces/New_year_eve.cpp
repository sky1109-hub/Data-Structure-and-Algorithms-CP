#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t=1;
    //cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll ans;
        if (k == 1) ans = n;
        else {
            ll p = 1;
            while (p <= n) p <<= 1; 
            ans = p - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
