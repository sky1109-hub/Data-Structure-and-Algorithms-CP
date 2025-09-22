#include <bits/stdc++.h>
using namespace std;
int solve(int i,int j,string s,string p){
    if(i<0){
        return j+1;
    } if(j<0){
        return i+1;
    }
    if(s[i]==s[j]){
        return solve(i-1,j-1,s,p);
    }
        return 1+min({solve(i-1,j,s,p),solve(i,j-1,s,p),solve(i-1,j-1,s,p)});
    
}
int main(){
  string s,p;
  cin>>s>>p;
  cout<<solve(s.size()-1,p.size()-1,s,p);
return 0;
}