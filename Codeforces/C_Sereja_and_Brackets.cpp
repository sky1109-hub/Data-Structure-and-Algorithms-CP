#include <bits/stdc++.h>
using namespace std;

struct node {
    int f, o, c;
    node() : f(0), o(0), c(0) {}
};

class segment {
public:
    int n;
    vector<node> seg;

    segment(int x) {
        n = x;
        seg.resize(4 * n);
    }

    node merge(node a, node b) {
        node res;
        int m = min(a.o, b.c);
        res.f = a.f + b.f + m;
        res.o = a.o + b.o - m;
        res.c = a.c + b.c - m;
        return res;
    }

    void build(int idx, int l, int r, const string &s) {
        if (l == r) {
            if (s[l] == '(') seg[idx].o = 1;
            else seg[idx].c = 1;
            return;
        }
        int m = (l + r) / 2;
        build(idx * 2 + 1, l, m, s);
        build(idx * 2 + 2, m + 1, r, s);
        seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }

    node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return node();
        if (ql <= l && r <= qr) return seg[idx];
        int m = (l + r) / 2;
        node left = query(idx * 2 + 1, l, m, ql, qr);
        node right = query(idx * 2 + 2, m + 1, r, ql, qr);
        return merge(left, right);
    }
};

int main() {
    string s;
    cin >> s;
    int n = s.size();

    segment st(n);
    st.build(0, 0, n - 1, s);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        node ans = st.query(0, 0, n - 1, l - 1, r - 1);
        cout << ans.f * 2 << "\n";
    }
    return 0;
}
