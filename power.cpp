#include <bits/stdc++.h>
using namespace std;
int power(int a ,int x){
    if(x==0) return 1;
     x=x>0?x-1:x+1;
    return a*power(a,x);
      
}
int main(){

    int a,x;
    cin>>a>>x;
    if(x<0) cout<< (double)1/power(a,x);
    else cout<<power(a,x);
   
    
return 0;
}