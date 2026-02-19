#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dp[101][101];

int solve(int i, int j, vector<int> &a)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    for (int k = i + 1; k < j; k++)
    {
        int cost = a[i] * a[k] * a[j] + solve(i, k, a) + solve(k + 1, j, a);

        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));

    cout << solve(0, n - 2, a) << endl;

    return 0;
}
