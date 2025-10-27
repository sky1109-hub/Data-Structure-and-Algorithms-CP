#include <bits/stdc++.h>
using namespace std;
vector<int> seg, lazy, a;
void build(int idx, int low, int high)
{
    if (low == high)
    {
        seg[idx] = a[low];
        return;
    }
    int m = (low + high) / 2;
    build(2 * idx + 1, low, m);
    build(2 * idx + 2, m + 1, high);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(int idx, int low, int high, int l, int r)
{
    if (l > high || r < low)
        return INT_MAX;
    if (l <= low && r >= high)
    {
        return seg[idx];
    }
    int m = (low + high) / 2;
    int left = query(2 * idx + 1, low, m, l, r);
    int right = query(2 * idx + 2, m + 1, high, l, r);
    return min(left, right);
}
int query(int l, int r)
{
    return query(0, 0, a.size() - 1, l, r);
}
void update(int idx, int l, int r, int i, int val)
{
    if (l == r)
    {
        seg[idx] = val;
        return;
    }
    int m = (l + r) / 2;
    if (i <= m)
        update(2 * idx + 1, l, m, i, val);
    else
        update(2 * idx + 2, m + 1, r, i, val);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}
void update(int i, int val)
{
    return update(0, 0, a.size() - 1, i, val);
}
void push(int idx, int l, int r)
{
    if (lazy[idx] != 0)
    {
        seg[idx] +=  lazy[idx];
        if (l != r)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}
void range(int idx, int l, int r, int low, int high, int val)
{
    push(idx, low, high);
    // no overlap
    if (l > high || r < low)
        return;
    // full overlap
    if (l <= low && r >= high)
    {
        lazy[idx] += val;
        push(idx, low, high);
        return;
    }
    int m = (low + high) / 2;
    range(2 * idx + 1, l, r, low, m, val);
    range(2 * idx + 2, l, r, m + 1, high, val);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}
int main()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    a = b;
    seg.resize(4 * n);
    lazy.resize(4 * n, 0);

    build(0, 0, n - 1);
    int x, y, i, val;
    cout << "Query before: ";
    cin >> x >> y;
    cout << query(x, y) << endl;
    cout << "update: ";
    cin >> i >> val;
    update(i, val);
    cout << "same query result after updation: " << query(x, y);

    return 0;
}