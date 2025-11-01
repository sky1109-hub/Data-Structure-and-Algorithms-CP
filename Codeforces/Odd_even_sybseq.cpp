#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int possible(vector<int> &a, int m, int n,int k)
{
    int maxev = INT_MIN, maxodd = INT_MIN;
    for (int i = m; i < (min(m+k,n)); i++)
    {
        if ((i + 1) % 2 == 0)
        {
            maxev = max(maxev, a[i]);
        }
        else
        {
            maxodd = max(maxodd, a[i]);
        }
    }
    return min(maxodd,maxev);
}
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, h = n, ans = 0;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (possible(a, m, n,k) >= k)
        {
            ans = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans << endl;

    return 0;
}