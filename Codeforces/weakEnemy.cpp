#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> seg;

int query(int idx, int ql, int qr, int l, int r) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return seg[idx];
    int m = (l + r) >> 1;
    return query(2*idx+1, ql, qr, l, m) + query(2*idx+2, ql, qr, m+1, r);
}

void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        seg[idx] += val;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m) update(2*idx+1, l, m, pos, val);
    else update(2*idx+2, m+1, r, pos, val);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int m = (int)b.size();
    unordered_map<int,int> mp;
    for (int i = 0; i < m; ++i) mp[b[i]] = i;

    if (m == 0) { cout << 0 << '\n'; return 0; }

    seg.assign(4*m, 0);
    vector<ll> leftGreater(n, 0), rightSmaller(n, 0);

    for (int i = 0; i < n; ++i) {
        int pos = mp[a[i]];
        if (pos < m-1) leftGreater[i] = query(0, pos+1, m-1, 0, m-1);
        else leftGreater[i] = 0;
        update(0, 0, m-1, pos, 1);
    }

    fill(seg.begin(), seg.end(), 0);

    for (int i = n-1; i >= 0; --i) {
        int pos = mp[a[i]];
        if (pos > 0) rightSmaller[i] = query(0, 0, pos-1, 0, m-1);
        else rightSmaller[i] = 0;
        update(0, 0, m-1, pos, 1);
    }

    ll res = 0;
    for (int i = 0; i < n; ++i) res += leftGreater[i] * rightSmaller[i];

    cout << res << '\n';
    return 0;
}
