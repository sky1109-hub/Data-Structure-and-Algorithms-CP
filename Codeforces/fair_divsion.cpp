#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int c1 = 0, c2 = 0, x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x == 1) c1++;
            else c2++;
        }

        int sum = c1 + 2 * c2;
        if (sum % 2 != 0) {
            cout << "NO\n";
        } 
        else {
            int half = sum / 2;
            if (half % 2 == 1 && c1 == 0) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}
