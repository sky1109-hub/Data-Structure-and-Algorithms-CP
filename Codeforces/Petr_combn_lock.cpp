// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     ll n;
//     cin >> n;
//     vector<int> a(n);
//     ll s = 0;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         s += a[i];
//     }

//     if (s & 1) {
//         cout << "No\n";
//         return 0;
//     }  if(s==360 ||s==0){
//           cout << "Yes\n";
//         return 0;
//     }

//     ll t = s / 2;
//     vector<vector<bool>> dp(n, vector<bool>(t + 1, false));

//     for (int i = 0; i < n; i++)
//         dp[i][0] = true;

//     if (a[0] <= t)
//         dp[0][a[0]] = true;

//     for (int i = 1; i < n; i++) {
//         for (int j = 1; j <= t; j++) {
//             bool not_take = dp[i - 1][j];
//             bool take = false;
//             if (a[i] <= j)
//                 take = dp[i - 1][j - a[i]];
//             dp[i][j] = take || not_take;
//         }
//     }

//     cout << (dp[n - 1][t] ? "Yes" : "No") << endl;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    bool ok = false;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += a[i];
            else sum -= a[i];
        }
        if ((sum % 360 + 360) % 360 == 0) ok = true;
    }

    cout << (ok ? "Yes" : "No") << endl;
}
