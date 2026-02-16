#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        int nc=0;  if(l==n) nc++;
        if(r==n) nc++;
        if(d==n) nc++;
        if(u==n) nc++;
        if(nc==4){
            cout<<"Yes\n";
        }else if(nc==3){
             if(l<2||r<2||d<2||u<2){
                cout<<"NO\n";
             }else {
                cout<<"Yes\n";
             }
        }else if(nc==2){
            if(l==n&&r==n){
                 if(u<2||d<2)  cout<<"No\n";
                 else cout<<"Yes\n";

            }else if(u==n&&d==n){
                if(l<2||r<2)  cout<<"No\n";
                 else cout<<"Yes\n";
            }
        }
       
    }
    return 0;
}