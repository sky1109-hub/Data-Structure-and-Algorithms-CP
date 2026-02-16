#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
     
    int t; cin>>t;
    while(t--){
        ll ans=0;
        char a[11][11];
        for(int i=1;i<=10;i++){
            for(int j=1;j<=10;j++){
                cin>>a[i][j];
                if(a[i][j]=='X'){
                    int k=min({i,j,10-i+1,10-j+1});
                   // cout<<"k: "<<k;
                    ans+=k;

                }
            }
        } cout<<ans<<endl;
    }
return 0;
}