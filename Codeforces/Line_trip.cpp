#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
 int t;cin>>t;
 while(t--){
     int n,x,ma=INT_MIN;
     cin>>n>>x;
     vector<int>a(n);
     for(int i=0;i<n;i++){
         cin>>a[i];
          ma=max(ma,(a[i]-(i==0?0:a[i-1])));
     }
     ma=max(ma,2*(x-a[n-1]));
     cout<<ma<<endl;

 }
return 0;
}