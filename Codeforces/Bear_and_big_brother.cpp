#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a,b,ans=0;
  cin>>a>>b;
  while(a<=b){
    a*=3;
    b*=2;
    ans++;
  }
   cout<<ans;
return 0;
}