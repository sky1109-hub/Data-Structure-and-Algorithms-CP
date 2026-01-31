#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,ans=1e9; cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ans=min(ans,abs(x));
    }
    cout<<ans<<endl;

return 0;
}