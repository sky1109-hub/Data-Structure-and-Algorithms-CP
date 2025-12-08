#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];

    for (int mask = 0; mask < (1 << 4); mask++) {
        vector<int> t;

        for (int j = 0; j < 4; j++) {
            if (mask & (1 << j)) {
                t.push_back(a[j]);
            }
        }

        if (t.size() != 3) continue;

        sort(t.begin(), t.end());  

        if (t[0] + t[1] > t[2]) {
            cout << "TRIANGLE";
            return 0;
        }
        if (t[0] + t[1] == t[2]) {
            cout << "SEGMENT";
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
