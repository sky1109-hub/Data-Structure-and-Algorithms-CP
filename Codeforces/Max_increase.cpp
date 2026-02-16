#include <bits/stdc++.h>
using namespace std;
int main(){
int n;cin>>n;
vector<int>a(n);
int c=1,ans=1;
for(int i=0;i<n;i++)  cin>>a[i];
for(int i=0;i<n-1;i++){
    if(a[i]<a[i+1]) {
         c++; ans=max(ans,c);
    }
    else c=1;
}  cout<<ans;
return 0;
}