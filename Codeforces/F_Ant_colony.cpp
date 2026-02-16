
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll g, mn;
    int cnt;
};

class segment {
public:
    int n;
    vector<Node> seg;

    segment(int x, vector<ll>& a) {
        n = x;
        seg.resize(4 * n);
        build(0, 0, n - 1, a);
    }

    void build(int idx, int l, int r, vector<ll>& a) {
        if (l == r) {
            seg[idx] = {a[l], a[l], 1};
            return;
        }
        int m = (l + r) / 2;
        build(2 * idx + 1, l, m, a);
        build(2 * idx + 2, m + 1, r, a);

        seg[idx].g = gcd(seg[2 * idx + 1].g, seg[2 * idx + 2].g);
        seg[idx].mn = min(seg[2 * idx + 1].mn, seg[2 * idx + 2].mn);

        if (seg[2 * idx + 1].mn < seg[2 * idx + 2].mn)
            seg[idx].cnt = seg[2 * idx + 1].cnt;
        else if (seg[2 * idx + 1].mn > seg[2 * idx + 2].mn)
            seg[idx].cnt = seg[2 * idx + 2].cnt;
        else
            seg[idx].cnt = seg[2 * idx + 1].cnt + seg[2 * idx + 2].cnt;
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return {0, LLONG_MAX, 0};

        if (ql <= l && r <= qr)
            return seg[idx];

        int m = (l + r) / 2;
        Node left = query(2 * idx + 1, l, m, ql, qr);
        Node right = query(2 * idx + 2, m + 1, r, ql, qr);

        Node res;
        res.g = gcd(left.g, right.g);
        res.mn = min(left.mn, right.mn);

        if (left.mn < right.mn)
            res.cnt = left.cnt;
        else if (left.mn > right.mn)
            res.cnt = right.cnt;
        else
            res.cnt = left.cnt + right.cnt;

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    segment s(n, a);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        Node res = s.query(0, 0, n - 1, l, r);
        int len = r - l + 1;

        if (res.g == res.mn)
            cout << len - res.cnt << "\n";
        else
            cout << len << "\n";
    }
    return 0;
}
