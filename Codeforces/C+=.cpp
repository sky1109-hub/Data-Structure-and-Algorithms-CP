#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, n;
        cin >> a >> b >> n;

        int cnt = 0;
        while (max(a, b) <= n) {
            if (a < b)
                a += b;
            else
                b += a;
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
