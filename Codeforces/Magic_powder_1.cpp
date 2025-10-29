#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> nec(n), st(n);
    for (int i = 0; i < n; i++)
        cin >> nec[i];
    for (int i = 0; i < n; i++)
        cin >> st[i];

    ll l = 0, h = 1e9, ans = 0;
    while (l <= h)
    {
        ll m = l + (h - l) / 2;
        ll req = 0;

        for (int i = 0; i < n; i++)
        {
            ll req1 = st[i] - m * nec[i];
            if (req1 < 0)
            {
                req += req1;
            }
        }
        if (abs(req) <= k)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    cout << ans << endl;

    return 0;
}