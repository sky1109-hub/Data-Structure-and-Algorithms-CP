#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,maxi,prevf=0;
  cin>>n;
  vector<int>a(n),m(4,0);
       maxi=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    m[a[i]]++;}
    auto it=max_element(m.begin(),m.end());
  int rem=n-(*it);
   cout<<rem<<endl;

return 0;
}