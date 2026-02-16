#include <bits/stdc++.h>
using namespace std;
int nas=0;

int solve(int n,vector<int>&num){
    
    if(n<0)  return 0;
    if(n==0)  return 1;
    int s=0;
    for(int i=0;i<3;i++){
        s+=solve(n-num[i],num);
    }
     
    return max(s,nas);
    

}
int main(){
  int n,a,b,c;
  
  cin>>n>>a>>b>>c;
  vector<int>num={a,b,c};
  cout<<solve(n,num)<<endl;
return 0;
}