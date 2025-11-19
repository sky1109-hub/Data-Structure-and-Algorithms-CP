ll power(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return r;
} ll power(int a,int b){
    if(b==0)  return 1;
    ll x=power(a,b/2);
    if(b&1)  return a*x*x;
    return x*x;
}