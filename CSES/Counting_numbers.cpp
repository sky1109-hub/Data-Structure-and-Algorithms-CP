#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[19][11][2][2]; // idx, prev+1, tight, leading zero

ll fn(const string &s, int prev, int idx, int lz, int tight) {
    if (idx == (int)s.size()) return 1;
    ll &res = dp[idx][prev+1][tight][lz];
    if (res != -1) return res;
    res = 0;

    int up = tight ? (s[idx] - '0') : 9;
    for (int i = 0; i <= up; i++) {
        if (!lz && i == prev) continue; 
        res += fn(s, i, idx+1, lz && (i==0), tight && (i==up));
    }
    return res;
}

int main() {
    ll s1, s2;
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    ll right = fn(to_string(s2), -1, 0, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll left = fn(to_string(s1-1), -1, 0, 1, 1);
    cout << right - left << "\n";
    return 0;
}
