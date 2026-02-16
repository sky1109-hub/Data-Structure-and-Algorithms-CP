#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll t;cin>>t;
  while(t--){
    ll a,b,xk,yk,xq,yq;
    cin>>a>>b;
    cin>>xk>>yk;
    cin>>xq>>yq;
    int dx[4]={1,-1,-1,1},dy[4]={1,1,-1,-1};
    set<pair<int,int>>k_hit,q_hit;
    for(int i=0;i<4;i++){
        k_hit.insert({xk+dx[i]*a,yk+dy[i]*b});
         k_hit.insert({xk+dx[i]*b,yk+dy[i]*a});
          q_hit.insert({xq+dx[i]*a,yq+dy[i]*b});
           q_hit.insert({xq+dx[i]*b,yq+dy[i]*a});
    }
       ll ans = 0;
        for (auto &cell : k_hit) {
            if (q_hit.count(cell)) ans++;
        }

        cout << ans << "\n";
  }
return 0;
}