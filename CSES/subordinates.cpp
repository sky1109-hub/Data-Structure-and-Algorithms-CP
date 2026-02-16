#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> dp;
vector<vector<int>> adj;
void dfs(int node)
{
    int s = 0;
    for (auto it:adj[node]){
        dfs(it);
        s+=(1+dp[it]);
    }
    dp[node]=s;
}
int main()
{
    int n;
    cin >> n;
    dp.resize(n + 1, 0);
    adj.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    return 0;
}