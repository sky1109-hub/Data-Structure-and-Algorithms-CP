#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<bool>p(1e9,true);
void prime(){
    p[0]=p[1]=false;
    for(int i=2;i*i<1e9;i++)
    if(p[i]){
        for(int j=i*i;j<1e9;j+=i){
            p[j]=false;
        }
    }

}
void printp(ll m, ll n){
    while(m<=n){
      if(p[m])  cout<<m<<endl;
        m++;
    } cout<<endl;
}
int main(){
    prime();
    cout<<"INput:";
  ll t; cin>>t;
  
  while(t--){
     ll m,n;
     cin>>m>>n;
     printp(m,n);
  }
return 0;
}