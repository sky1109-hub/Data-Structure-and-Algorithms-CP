#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;  
    cin >> s;

    long long nb, ns, nc;
    cin >> nb >> ns >> nc;

    long long cb, cs, cc;
    cin >> cb >> cs >> cc;

    long long r;
    cin >> r;

    long long breq = 0, sreq = 0, creq = 0;
    for (auto it : s) {
        if (it == 'S') sreq++;
        else if (it == 'B') breq++;
        else if (it == 'C') creq++;
    }

    long long l = 0, h = 1e15, ans = 0;  // bigger upper bound
    while (l <= h) {
        long long m = l + (h - l) / 2;

        long long bq = max(0LL, breq * m - nb);
        long long sq = max(0LL, sreq * m - ns);
        long long cq = max(0LL, creq * m - nc);

        __int128 cost = (__int128)bq * cb + (__int128)sq * cs + (__int128)cq * cc;

        if (cost <= r) {
            ans = m;
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
