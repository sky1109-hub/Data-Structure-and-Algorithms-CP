#include <bits/stdc++.h>
using namespace std;
using ll=long long;
  int dp[20][2][10][2];
ll solve(string s,int idx,int lz,int prev,int tight){
     if(idx==s.size())   return 1;
     ll res=0;
     if(dp[idx][lz][prev][tight]!=-1)  return dp[idx][lz][prev][tight];
     int up=tight==1?s[idx]-'0':9;
     for(int i=0;i<=up;i++){
        if(lz&&i==0)  continue;
        res+=solve(s,idx+1,lz&&i==0,i,tight&&i==up);
     }
     return dp[idx][lz][prev][tight]=res;
  }
void solve1(ll l ,ll r){
    string s=to_string(r);
     memset(dp,-1,sizeof(dp)); 
     ll x2=solve(s,0,1,0,1);
      memset(dp,-1,sizeof(dp));
      s="";
      s=to_string(l);
    ll x1=solve(s,0,1,0,1);
   
    cout<<x2-x1<<endl;

} int main(){
ll  l,r;
cin>>l>>r;
solve1(l,r);

return 0;
}