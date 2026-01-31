#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool check(int c, int x, int p){
    if(c==10)  return 0;
  
    if((x+1)%3==0||(x-1)%3==0)  return (p==1?1:0);
     return check(c+1,x+1,!p)||check(c+1,x-1,!p);
}
int main(){
   int t;
   cin>>t;
   while(t--){
    int x; cin>>x;
     if(check(0,x,1)){
        cout<<"First"<<endl;
     } else{
         cout<<"Second"<<endl;
     }
   }
return 0;
}