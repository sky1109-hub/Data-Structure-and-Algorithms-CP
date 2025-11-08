#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll k,n,w;
  cin>>k>>n>>w;
  ll req=n-k*w*(w+1)/2;
  cout<<(req<0?abs(req):0)<<endl;
return 0;
}