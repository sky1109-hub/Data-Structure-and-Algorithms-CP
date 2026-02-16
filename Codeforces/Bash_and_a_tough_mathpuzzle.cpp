#include <bits/stdc++.h>
using namespace std;

class SegTree {
public:
    int n;
    vector<int> seg;
    vector<int> a;

    SegTree(int n, vector<int> &arr) : n(n), a(arr) {
        seg.resize(4 * n);
        build(0, 0, n - 1);
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = a[l];
            return;
        }
        int m = l + ((r - l) >> 1);
        build(idx*2+1, l, m);
        build(idx*2+2, m+1, r);
        seg[idx] = gcd(seg[idx*2+1], seg[idx*2+2]);
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;  
        if (ql <= l && r <= qr) return seg[idx];
        int m = l + ((r - l) >> 1);
        return gcd(
            query(idx*2+1, l, m, ql, qr),
            query(idx*2+2, m+1, r, ql, qr)
        );
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = val;
            a[l] = val;
            return;
        }
        int m = l + ((r - l) >> 1);
        if (pos <= m) update(idx*2+1, l, m, pos, val);
        else update(idx*2+2, m+1, r, pos, val);
        seg[idx] = gcd(seg[idx*2+1], seg[idx*2+2]);
    }

    // find first index >= L where a[i] % z != 0
    int find_bad(int idx, int l, int r, int L, int R, int z) {
        if (r < L || l > R) return -1;

        // If on this segment gcd is divisible by z, NO bad element.
        if (seg[idx] % z == 0) return -1;

        // If we are at leaf, this leaf is bad.
        if (l == r) return l;

        int m = l + ((r - l) >> 1);
        int left = find_bad(idx*2+1, l, m, L, R, z);
        if (left != -1) return left;
        return find_bad(idx*2+2, m+1, r, L, R, z);
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    SegTree st(n, a);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r, z;
            cin >> l >> r >> z;
            l--, r--;

            int g = st.query(0, 0, n - 1, l, r);

            if (g == z) {
                cout << "YES\n";
                continue;
            }

            // find first violating index
            int p1 = st.find_bad(0, 0, n - 1, l, r, z);
            if (p1 == -1) { 
                // NO violation means gcd != z but all divisible -> canNOt fix
                cout << "NO\n";
                continue;
            }

            // find second violating index starting from p1+1
            int p2 = st.find_bad(0, 0, n - 1, p1 + 1, r, z);

            if (p2 == -1) cout << "YES\n";  
            else cout << "NO\n";

        } else {
            int pos, val;
            cin >> pos >> val;
            pos--;
            st.update(0, 0, n - 1, pos, val);
        }
    }

    return 0;
}
