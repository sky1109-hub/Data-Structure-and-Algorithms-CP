#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 10, 3, 4, 29};
    int n = a.size();
    int ans = 2;  // at least 2 elements form AP

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = a[j] - a[i];
            int last = a[j];  // start from j
            int l = 2;

            for (int k = i - 1; k >= 0; k--) {
                if (last - a[k] == d) {
                    l++;
                    last = a[k];
                }
            }

            ans = max(ans, l);
        }
    }

    cout << ans << endl;
    return 0;
}
