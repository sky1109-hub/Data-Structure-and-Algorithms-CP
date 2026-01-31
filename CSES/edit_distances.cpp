#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, string s, string p)
{
    if (i == 0)
    {
        return j + 1;
    }
    if (j == 0)
    {
        return i + 1;
    }
    if (s[i - 1] == s[j - 1])
    {
        return solve(i - 1, j - 1, s, p);
    }
    return 1 + min({solve(i - 1, j, s, p), solve(i, j - 1, s, p), solve(i - 1, j - 1, s, p)});
}
int main()
{
    string s, p;
    cin >> s >> p;
    // cout<<solve(s.size(),p.size(),s,p);
    int m = s.size(), n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == p[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    cout << dp[m ][n ] << endl;

    return 0;
}