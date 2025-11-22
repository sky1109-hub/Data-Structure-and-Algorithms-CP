#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class segment
{
    int n;

public:
    vector<ll> seg;
    segment(int x) : n(x)
    {
        seg.assign(4 * x, 0);
    }

    void update(int idx, int l, int r, int pos)
    {
        if (l == r)
        {
            seg[idx]++;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(idx * 2 + 1, l, mid, pos);
        else
            update(idx * 2 + 2, mid + 1, r, pos);
        seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    }

    ll query(int idx, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return seg[idx];
        int mid = (l + r) / 2;
        return query(idx * 2 + 1, l, mid, ql, qr) + query(idx * 2 + 2, mid + 1, r, ql, qr);
    }

    void reset()
    {
        fill(seg.begin(), seg.end(), 0LL);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> comp = a;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    int m = comp.size();
    segment s(m);

    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        val[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
    }

    vector<ll> left(n, 0), right(n, 0);

    // First pass: count greater elements on left
    for (int i = 0; i < n; i++)
    {
        int x = val[i];

        left[i] = s.query(0, 0, m - 1, x + 1, m - 1);
        s.update(0, 0, m - 1, x);
    }

    s.reset();

    for (int i = n - 1; i >= 0; i--)
    {
        int x = val[i];
        
            right[i] = s.query(0, 0, m - 1, 0, x - 1);
        s.update(0, 0, m - 1, x);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += left[i] * right[i];
    }

    cout << ans << "\n";
    return 0;
}
