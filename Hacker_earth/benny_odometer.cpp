#include <bits/stdc++.h>
using namespace std;
int dp[12][2][2];
  int solve(string s,int idx,int tight,int flag){
    if(idx==s.size()) return  flag;
    if(dp[idx][tight][flag]!=-1)  return dp[idx][tight][flag];
    int limit=tight==1?s[idx]-'0':9;
    int ans=0;
    for(int i=0;i<=limit;i++){
        int upd=flag|(i==3);
        ans+=solve(s,idx+1,tight&(i==limit),upd);
    }
         return dp[idx][tight][flag]=ans;
  }
  int helper(int x){
    string s=to_string(x);
    memset(dp,-1,sizeof(dp));
      return solve(s,0,1,0);
   
  }
int main(){
int t;
cin>>t;
while(t--){
    int n;cin>>n;
    cout<<n-helper(n)<<endl;
}

return 0;
}