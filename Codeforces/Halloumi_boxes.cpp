#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool check(vector<int>&a){
    vector<int>b=a;
    sort(b.begin(),b.end());
    return a==b;
}
int main(){
  ll t; cin>>t;
  while(t--){
    ll n,k; cin>>n>>k;
    vector<int>a(n);
      for(int i=0;i<n;i++)  cin>>a[i];
    if(k==1){
        if(check(a)){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;

        
    }
   else  cout<<"Yes"<<endl;
  
  }
return 0;
}