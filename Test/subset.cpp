#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n;  cin>>n;
    vector<int>a(n);
   for(int i=0;i<n;i++){
     cin>>a[i];
   }
  int limit=(1<<n);
 
   for(int i=0;i<limit;i++){
    int  j=i,c=0;
    cout<<"{ ";
    while(j!=0){
     if(j&1)  {
        cout<<a[c]<<" ";
     }
       c++;
       j=j>>1;
      
    } 
    cout<<" }"<<endl;
   }
return 0;
}