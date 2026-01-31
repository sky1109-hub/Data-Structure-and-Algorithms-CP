#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
 ll n,m,k;
 cin>>n>>m>>k;
 vector<vector<ll>>adj(n,vector<ll>(m));
 vector<ll>ans;
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        adj[i][j]=(i+1)*(j+1);
    }
    ans.insert(ans.end(),adj[i].begin(),adj[i].end());
 } sort(ans.begin(),ans.end());
   cout<<ans[k-1];
return 0;
}