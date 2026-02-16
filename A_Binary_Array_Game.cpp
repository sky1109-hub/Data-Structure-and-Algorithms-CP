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

        int zeros = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) zeros++;
        }

        if (zeros % 2 == 1)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    return 0;
}
