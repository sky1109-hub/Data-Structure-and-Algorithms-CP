#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, l, r, x, ans = 0;
    cin >> n >> l >> r >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int limit = (1 << n); // ✅ fixed

    for (int i = 0; i < limit; i++) {
        if (__builtin_popcount(i) < 2) continue; 
        
        ll s = 0, mi = LLONG_MAX, ma = LLONG_MIN;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                s += a[j];
                ma = max(ma, a[j]);
                mi = min(mi, a[j]);
            }
        }

        if (s >= l && s <= r && ma - mi >= x) ans++; 
    }

    cout << ans;
    return 0;
}
