#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll can(ll cap) {
    ll ret = 0;
    for (ll x = 2; x * x * x <= cap; x++) {
        ret += cap / (x * x * x);
    }
    return ret;
}

int main() {
    ll n;
    cin >> n;

    ll l = 0, h = 1e18, ans = -1;
    while (l <= h) {
        ll mid = l + (h - l) / 2;
        ll ret = can(mid);
        if (ret >= n) {
            if (ret == n) ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
