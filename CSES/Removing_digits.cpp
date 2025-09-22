#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int solve(int n) {
    if (n == 0) return 0;  
    
    int ans = INT_MAX;
    string k = to_string(n);
    for (auto it : k) {
        int d = it - '0';
        if (d == 0) continue;
        ans = min(ans, 1 + solve(n - d));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
   // cout << solve(n) << endl;
   vector<int>dp(n+1,INT_MAX);
   dp[0]=0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        while (x > 0) {
            int d = x % 10;
            x /= 10;
            if (d > 0) {
                dp[i] = min(dp[i], 1 + dp[i - d]);
            }
        }
    }

    cout << dp[n] << "\n";
   
    return 0;
}
