#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
int n; cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++)  cin>>a[i];
int x; cin>>x;
vector<int>pre(n+1,0);
unordered_map<int,int>mp;
mp[0]=1;
for(int i=0;i<n;i++){
    p[i+1]=a[i]+p[i];
    mp[p[i+1]]=i;

}
for(int i=0;i<=n;){
   int y=p[i]+x;
   if(mp.find(y)!=mp.end()){
     int z=mp[y];
    for(int j=i+1;j<=z-1;j++){
        a[i]=-1;

    }
     i=z+1;
     

   }else{
    i++;
   }
   
}
for(int )


return 0;
}