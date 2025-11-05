#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

ll power(ll x, ll y) {
    ll res = 1;
    x %= mod;
    while(y) {
        if(y & 1) 
            res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

int main() {
    ll n, x;
    cin >> n >> x;
    
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    unordered_map<ll, ll> cnt;
    for(int i = 0; i < n; i++) {
        cnt[ sum - a[i] ]++;
    }

    ll cur = sum - a[n-1];

    while(cnt[cur] % x == 0) {
        cnt[cur+1] += cnt[cur] / x;
        cnt[cur] = 0;
        cur++;
    }

    cout << power(x, cur) << "\n";
    return 0;
}
