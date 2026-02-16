#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class segment {
    int n;
    vector<ll> seg, lazy;

public:
    segment(int _n, vector<int> &a) : n(_n) {
        seg.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(a, 0, 0, n-1);
    }

    void build(vector<int> &a, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = a[l];
            return;
        }
        int m = (l+r)/2;
        build(a, idx*2+1, l, m);
        build(a, idx*2+2, m+1, r);
        seg[idx] = min(seg[idx*2+1], seg[idx*2+2]);
    }

    void push(int idx, int l, int r) {
        if (lazy[idx] != 0) {
           

            if (l != r) {
                lazy[idx*2+1] += lazy[idx];
                lazy[idx*2+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void rangeupd(int idx, int ql, int qr, int l, int r, ll val) {
        push(idx, l, r);

        if (qr < l || ql > r)
            return;

        if (ql <= l && r <= qr) {
            lazy[idx] += val;
             seg[idx] += lazy[idx];  
            push(idx, l, r);
            return;
        }

        int m = (l+r)/2;
        rangeupd(idx*2+1, ql, qr, l, m, val);
        rangeupd(idx*2+2, ql, qr, m+1, r, val);
        seg[idx] = min(seg[idx*2+1], seg[idx*2+2]);
    }

    ll query(int idx, int ql, int qr, int l, int r) {
        push(idx, l, r);

        if (qr < l || ql > r)
            return LLONG_MAX;

        if (ql <= l && r <= qr)
            return seg[idx];

        int m = (l+r)/2;
        return min(
            query(idx*2+1, ql, qr, l, m),
            query(idx*2+2, ql, qr, m+1, r)
        );
    }
};


int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    segment s(n, a);

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
      if(x==1)  s.rangeupd(0, y-1, y-1, 0, n-1, z);
      else  cout << s.query(0, y-1, z-1, 0, n-1) << "\n";
    }

    return 0;
}
