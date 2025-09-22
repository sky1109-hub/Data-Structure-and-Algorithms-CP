#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int solve(int idx, vector<int> &c, int s)
{
    if (idx == c.size())
        return 0;
    if (s < 0)
        return 0;
    if (s == 0)
        return 1;

    int nt = solve(idx + 1, c, s);
    int t = solve(idx, c, s - c[idx]);
    return t + nt;
}
int main()
{
    int n, S;
    cin >> n >> S;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(c.begin(), c.end());
    // cout << solve(0, c, s) << endl;
   vector<vector<int>> dp(n + 1, vector<int>(S + 1, 0));

    
    dp[n][0] = 1;

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int s = 0; s <= S; s++) {
            int notTake = dp[idx + 1][s];
            int take = 0;
            if (s - c[idx] >= 0) take = dp[idx][s - c[idx]]; 
            dp[idx][s] = (take + notTake)%mod;
        }
    }
    cout<< dp[0][S];
   
    return 0;
}