#include<iostream>
#include<vector>
using namespace std;
sieve(vector<bool>&p,int n){
    for(int i=2;i<=n;i++){
        if(p[i]){
            for(int j=i*i;j<=n;j+=i){
               p[j]=false;
            }
        }
        
    }
}
  
int main(){
int n; cin>>n;
vector<bool>p(n+1,true);
p[0]=p[1]=false;
sieve(p,n);
int c=0;
for(int i=0;i<=n;i++){
    if(p[i]){
        cout<<i<<" ";
        c++;
    } if(c%10==0){
        cout<<endl;
    }
}
  
return 0;
}