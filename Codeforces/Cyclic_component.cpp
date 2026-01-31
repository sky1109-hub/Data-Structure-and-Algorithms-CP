#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> adj;
vector<int>vis;
bool dfs(int node,int prev){
    if(node==prev){
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]])  return false;
        }
        return true;
    }
      if(adj[node].size()>2)  return false;
    vis[node];
            
     
   
}
int main()
{
    int n, m;
    cin >> n >> m;
    vis.resize(n+1,0);
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }  int c=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
          c+=  dfs(i,-1);
           
        }
    } cout<<c<<endl;
    return 0;
}