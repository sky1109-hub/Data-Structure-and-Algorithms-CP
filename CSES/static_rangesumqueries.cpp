// #include <bits/stdc++.h>
// using namespace std;
// using ll=long long;
// ll main(){
//  ll n,q;cin>>n>>q;
//  vector<ll>a(n+1);
//  vector<ll>pre(n+2,0);
 
//  for(ll i=1;i<=n;i++ ) {
//     cin>>a[i];
//     if(i==1)  pre[i]=a[i];
//     else pre[i]=pre[i-1]+a[i];
//  }
 
 
//   while(q--){
//     ll x,y;
//     cin>>x>>y;
//     cout<<pre[y]-pre[x-1]<<endl;

//  }

// return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class segment{
    int n;
    vector<int>a;
    vector<ll>seg;
    public:
    segment(int _n,vector<int>&_a): n(_n){
        a=_a;
        seg.resize(4*n,0);
        build(0,0,n-1);
    }
    void build(int idx,int l,int r){
        if(l==r){
            seg[idx]=a[l];
            return ;
        }
        ll m=l+(r-l)/2;
        build(2*idx+1,l,m);
        build(2*idx+2,m+1,r);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    ll query(int idx,int ql,int qr,int l,int r){
        if(ql>r||qr<l)  return 0;
        if(ql<=l&&qr>=r)  return seg[idx];
        ll m=l+(r-l)/2;
        ll l1=query(2*idx+1,ql,qr,l,m);
        ll r1=query(2*idx+2,ql,qr,m+1,r);
        return l1+r1;

    }

};
int main(){
    int n,q;
    cin>>n>>q;
   
    vector<int>a(n);
    for(int i=0;i<n;i++)  cin>>a[i];
     segment s(n,a);
     while(q--){
        int x,y; cin>>x>>y;
        cout<<s.query(0,x-1,y-1,0,n-1)<<endl;
     }

return 0;
}