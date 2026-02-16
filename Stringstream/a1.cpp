#include <bits/stdc++.h>
using namespace std;
int main(){
  string data="10  20   30";
    stringstream ss(data);
    cout<<"data: "<<data<<endl;
    int  x,k;
    while(ss>>x){
     k+=x;
     cout<<x<<" ";
    } cout<<"Sum: "<<k; 

return 0;
}