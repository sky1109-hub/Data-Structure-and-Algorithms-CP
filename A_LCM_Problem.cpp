#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;

        ll x = -1, y = -1;
        if (r >= 2 * l)
        {
            x = l, y = 2 * l;
        }
        cout << x << " " << y << endl;
    }
    return 0;
}