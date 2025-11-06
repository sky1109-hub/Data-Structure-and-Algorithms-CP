#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll>sub;
 vector<vector<int>>adj;
  int dfs(int u,vector<int>&vis){
       int s=0;
       queue<int>q;
       q.push(u);
       while(!q.empty()){
        int x=q.size();
        for(int i=0;i<x;i++){
              auto node=q.front();q.pop();
              if(!vis[node]){
                q.push(adj)
              }
        }
       
        
       }

  }
int main(){
  ll n;

  cin>>n;
  if(n==1){
    cout<<0;
    return 0;
  } sub.resize(n+1,0);
  adj.resize(n+1);
 vector<int>adj[n+1];
  for(int i=0;i<n-1;i++){
     int x, y;
     cin>>x>>y;
     adj[x].push_back(y);
     adj[y].push_back(x);
  }  int ans=0;
  for(int i=1;i<=n;i++){
    vector<int>vis(n+1,0);
    vis[i]=1;
    ans=max(ans,int(dfs(i,vis)));

  }  cout<<ans*3<<endl;
  

return 0;
}