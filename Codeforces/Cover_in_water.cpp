#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int t;  cin>>t;
  while(t--){
   int n; cin>>n;
   string s; cin>>s;
     int cnt=0;
    for(int i=1;i<n-2;i++){
      if(s[i-1]=='.'&&s[i+1]=='.'&&s[i]=='.'){
         cnt+=2;
         s[i-1]=s[i]=s[i+1]='#';

      }
  }

return 0;
}