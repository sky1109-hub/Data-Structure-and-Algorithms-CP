#include <bits/stdc++.h>
using namespace std;

vector<int> a, seg;

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, r);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

void update(int idx, int i, int val, int l, int r)
{
    if (l == r)
    {
        seg[idx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid)
        update(2 * idx + 1, i, val, l, mid);
    else
        update(2 * idx + 2, i, val, mid + 1, r);

    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(int idx, int l, int r, int low, int high)
{
    if (high < l || r < low)
        return INT_MAX;

    if (l >= low && r <= high)
        return seg[idx];

    int mid = (l + r) / 2;
    return min(query(2 * idx + 1, l, mid, low, high),
               query(2 * idx + 2, mid + 1, r, low, high));
}

int main()
{
    int n;
    cin >> n;
    a.resize(n);
    seg.resize(4 * n, INT_MAX);  // safer size

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(0, 0, n - 1);

    // Example usage
    int q;
    cin >> q; // number of queries

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << "Min in [" << l << "," << r << "] = "
                 << query(0, 0, n - 1, l, r) << endl;
        }
        else
        {
            int i, val;
            cin >> i >> val;
            update(0, i, val, 0, n - 1);
        }
    }

    return 0;
}
