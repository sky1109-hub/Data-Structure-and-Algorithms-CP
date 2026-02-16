#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[20][2][10][2];
ll solve(string s, int idx, int tight, int prev, int lz)
{
  if (idx == s.size())
    return 1;

  if (dp[idx][tight][prev][lz] != -1)
    return dp[idx][tight][prev][lz];
  int ub = tight ? (s[idx] - '0') : 9;
  ll ans = 0;
  for (int i = 0; i <= ub; i++)
  {
    int nt = tight && (i == ub);
    if (i == prev && !lz)
      continue;
    int nlz = (i == 0 && lz) ? 1 : 0;
    ans += solve(s, idx + 1, nt, i, nlz);
  }
  return  dp[idx][tight][prev][lz]=ans ;
}
ll query(ll x, ll y)
{
  string s = to_string(y);
  memset(dp, -1, sizeof(dp));

  ll ans2 = solve(s, 0, 1, 0, 1);

  s.clear();
  s = to_string(x-1);
  memset(dp, -1, sizeof(dp));
  ll ans1 = solve(s, 0, 1, 0, 1);

  return ans2 - ans1;
}
int main()
{
  ll x, y;
  cin >> x >> y;
  cout << query(x, y);
  return 0;
}