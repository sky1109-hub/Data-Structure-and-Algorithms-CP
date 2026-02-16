#include <bits/stdc++.h>
using namespace std;\
using ll=long long;
bool check(ll s){
    ll root = sqrtl(s);
return root * root == s || (root+1)*(root+1) == s;

}
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    ll s=0;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    if(check(s)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
return 0;
}