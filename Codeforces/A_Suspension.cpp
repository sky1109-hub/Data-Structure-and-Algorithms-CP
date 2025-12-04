#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int t; cin>>t;
    while(t--){
        int n ,y,r; 
        cin>>n>>y>>r;
        
        if(r>=n){
            cout<<n<<endl;
           
        }else{
            int s= r+y/2;
            cout<<min(s,n)<<endl;
        }
    }

return 0;
}