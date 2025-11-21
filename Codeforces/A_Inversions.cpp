#include <bits/stdc++.h>
using namespace std;

class segment {
    int n;
    vector<int> seg;

public:
    segment(int n) : n(n) {
        seg.assign(4 * n, 0);
    }

    void update(int idx, int l, int r, int pos) {
        if (l == r) {
            seg[idx]++;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(idx*2+1, l, m, pos);
        else update(idx*2+2, m+1, r, pos);
        seg[idx] = seg[idx*2+1] + seg[idx*2+2];
    }

    int query(int idx, int ql, int qr, int l, int r) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return seg[idx];
        int m = (l + r) / 2;
        return query(idx*2+1, ql, qr, l, m)
             + query(idx*2+2, ql, qr, m+1, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    segment s(n);

    for (int i = 0; i < n; i++) {
        int pos = a[i] - 1;                   
        cout << s.query(0, pos + 1, n - 1, 0, n - 1) << " ";
        s.update(0, 0, n - 1, pos);
    }
}
