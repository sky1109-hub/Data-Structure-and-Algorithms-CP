#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, x;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i <= n; i++)
  {
    while (cin >> x)
    {
      adj[i].push_back(x);
    }
  }
  vector<int> vis(n, 0);
  queue<int> q;
  q.push(0);
 
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    vis[node] = 1;
    cout << node << " ";
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        q.push(it);
      }
    }
  }

  return 0;
}