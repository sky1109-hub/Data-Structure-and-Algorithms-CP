#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n,ma=INT_MIN,mi=INT_MAX,maxi=n,mini=0; cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)  {
    cin>>a[i];
    if(a[i]<=mi){
        mi=a[i];
         mini=i;
    }
  } // cout<<mini<<endl;
  for(int i=n-1;i>=0;i--){
    if(a[i]>=ma) {
        ma=a[i];
        maxi=i;
    }
  }
    // cout<<maxi<<endl;
   if(mini<maxi){
    cout<<maxi+(n-2-mini)<<endl;
   }else{
    cout<<maxi+(n-1-mini)<<endl;
   }



return 0;
}