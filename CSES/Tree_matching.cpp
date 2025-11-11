#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n; cin>>n;
  vector<vector<int>>a(n+1);
  for(int i=1;i<n;i++){
    int x, y;
    cin>>x>>y;
    a[x].push_back(y);

  }
return 0;
}