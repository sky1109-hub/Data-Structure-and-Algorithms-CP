#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int s = 0, idx = 1;

    for (int i = 1; i <= k; i++)
        s += a[i];

    int cs = s;

    for (int i = k + 1; i <= n; i++) {
        cs = cs + a[i] - a[i - k];  

        if (cs < s) {
            s = cs;
            idx = i - k + 1;         
        }
    }

    cout << idx << endl;
    return 0;
}
