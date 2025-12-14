#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;
int n;
vector<long long> a1, a2;

long long solve(int i, int prev) {
    if (i >= n) return 0;

    if (dp[i][prev + 1] != -1) 
        return dp[i][prev + 1];

    long long best = 0;

   
    best = max(best, solve(i + 1, prev));


    if (prev != 0)
        best = max(best, a1[i] + solve(i + 1, 0));


    if (prev != 1)
        best = max(best, a2[i] + solve(i + 1, 1));

    return dp[i][prev + 1] = best;
}

int main() {
    cin >> n;

    a1.resize(n);
    a2.resize(n);
    dp.resize(n, vector<long long>(3, -1));

    for (int i = 0; i < n; i++) cin >> a1[i];
    for (int i = 0; i < n; i++) cin >> a2[i];

    cout << solve(0, -1);     
}
