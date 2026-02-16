#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge(int l, int m, int r, vector<int> &a)
{
    ll c = 0;

    int i = l, j = m + 1;
    vector<int> temp;

    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp.push_back(a[i++]);
        }
        else
        {
            c += (m - i + 1);   // count inversions
            temp.push_back(a[j++]);
        }
    }

    while (i <= m)
        temp.push_back(a[i++]);
    while (j <= r)
        temp.push_back(a[j++]);

    for (int k = l; k <= r; k++)
        a[k] = temp[k - l];

    return c;
}

ll mergesort(int l, int r, vector<int> &a)
{
    if (l >= r)
        return 0;

    int m = l + (r - l) / 2;

    ll c = 0;
    c += mergesort(l, m, a);
    c += mergesort(m + 1, r, a);
    c += merge(l, m, r, a);

    return c;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << mergesort(0, n - 1, a);

    return 0;
}
