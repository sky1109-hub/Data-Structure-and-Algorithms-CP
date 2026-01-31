#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {

    ll n; cin >> n;
    vector<ll> arr(n+1, 0);

    vector<ll> pref1(n+2, 0), pref2(n+2, 0);
    ll q; cin>>q;
    while(q--){
        ll l, r; cin>>l>>r;
        pref1[l]+=1; pref1[r+1]-=1;
        pref2[r+1]-=(r-l+1);
    }

    for(ll i=1;i<=n;i++) pref1[i]+=pref1[i-1];
    for(ll i=1;i<=n;i++){
        arr[i]=arr[i-1]+pref1[i]+pref2[i];
    }
    for(ll i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}