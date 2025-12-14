#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    int nz = 0, ma = 0, s = 0, s1 = 0;

    for (int i = 0; i < k; i++)
    {
        if (t[i])
            s1 += a[i];
        else
        {
            nz++;
            s += a[i];
        }
    }
    if (nz)
        ma = s;
    for (int i = k; i < n; i++)
    {
        if (t[i - k] == 0)
        {
            nz--;
            s -= a[i - k];
        }
        if (t[i])
            s1 += a[i];
        else
           {
             s += a[i];
             nz++;
           }

        if (nz > 0)
        {
            ma = max(ma, s);
        }
    }
    cout << ma+s1 << endl;
    return 0;
}