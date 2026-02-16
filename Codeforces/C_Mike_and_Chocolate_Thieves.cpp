#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sol(ll n)
{
    ll ret = 0;
    for (ll k = 2; k * k <= n / k; k++)
    {
        ret += n / (k * k * k);
        if (ret > 1e15)
            return ret;
    }
    return ret;
}

int main()
{
    ll m;
    cin >> m;

    ll low = 1, high = 2e18;
    ll ans = -1;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll val = sol(mid);

        if (val == m)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (val < m)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << ans << endl;
}
