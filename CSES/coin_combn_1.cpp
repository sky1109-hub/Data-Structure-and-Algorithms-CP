#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int solve(int t,vector<int>&c,vector<int>&dp){
      if(t<0)  return 0;
    if(t==0)  return 1;
    if(dp[t]!=-1)  return dp[t];
    int ans=0;
    for(int i=0;i<c.size();i++){
        ans=(ans+solve(t-c[i],c,dp))%mod;
    }
    return  dp[t]= ans;
}
int main(){
  int n,t;
  cin>>n>>t;
  vector<int>c(n);
  for(int i=0;i<n;i++)  cin>>c[i];
  vector<int>dp(t+1,-1);
  cout<<solve(t,c,dp);
return 0;
}