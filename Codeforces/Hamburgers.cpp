#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    vector<ll> have(3), cost(3), req(3, 0);
    cin >> have[0] >> have[1] >> have[2];
    cin >> cost[0] >> cost[1] >> cost[2];

    ll r;
    cin >> r;

    for (char c : s) {
        if (c == 'B') req[0]++;
        else if (c == 'S') req[1]++;
        else if (c == 'C') req[2]++;
    }

    ll l = 0, h = 4e12, ans = 0;

    while (l <= h) {
        ll m = l + (h - l) / 2;

        ll need = 0;
        for (int i = 0; i < 3; i++) {
            ll used = m * req[i] - have[i];
            if (used > 0) need += used * cost[i];
            if (need > r) break; 
        }

        if (need <= r) {
            ans = m;
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
