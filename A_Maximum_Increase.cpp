#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n; cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int  l=1,prev=a[0],ans=1;
    for(int i=1;i<n;i++){
        if(a[i]>prev){
            l++;
            prev=a[i];
            ans=max(ans,l);
        }else{
            l=1;
            prev=a[i];
        }
    }
    
    cout<<ans<<endl;


return 0;
}