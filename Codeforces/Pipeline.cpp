#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    __int128 total = (__int128)k * (k - 1) / 2;
    if (n - 1 > total) {
        cout << -1;
        return 0;
    }

    ll l = 1, h = k - 1, ans = k - 1;
    while (l <= h) {
        ll m = l + (h - l) / 2;
        __int128 s = (__int128)(2 * k - m - 1) * m / 2;

        if (s >= n - 1) {
            ans = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
