#include <bits/stdc++.h>
using ll=long long;
using namespace std;
int main(){
ll  n,k,x,a,b,c;
cin>>n>>k;
cin>>x>>a>>b>>c;
vector<ll >nums(n+1);
nums[0]=x;

for(ll  i=1;i<=n;i++){
    nums[i]=(nums[i-1]*a+b)%c;
  
} ll  ans=0,fans=0;
for(ll  i=0;i<k;i++){
   ans+=nums[i];
}  //cout<<endl;
//cout<<ans<<" ";
fans=ans;
for(ll  i=1;i<=n-k;i++){
    
  ans= ans-nums[i-1]+nums[i+k-1];
   //cout<<ans<<" ";
   fans=ans^fans;
} //cout<<endl;
cout<<fans<<endl;
return 0;
}