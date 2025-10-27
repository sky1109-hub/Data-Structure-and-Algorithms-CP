#include <bits/stdc++.h>
using namespace std;
int main(){
  string data="10,20, 30";
  cout<<data<<endl;
  stringstream ss(data);
  int x;
  while(ss>>x){
    cout<<x<<endl;
  }
return 0;
}