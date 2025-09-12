#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{

    ll n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    ll total_drink = k * l;
    ll total_lime_slice = c * d;
    cout << min({total_drink / nl, total_lime_slice, p / np}) / n << endl;
    return 0;
}