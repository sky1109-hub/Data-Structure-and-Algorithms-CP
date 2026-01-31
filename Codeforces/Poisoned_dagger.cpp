#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, h;
        cin >> n >> h;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) cin >> a[i];

        ll l = 1, r = h, ans = h;
        while (l <= r) {
            ll m = l + (r - l) / 2;
            __int128 c = 0;

            for (ll i = 0; i < n - 1; i++) {
                c += min((ll)(a[i + 1] - a[i]), m);
            }
            c += m; 

            if (c >= h) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
