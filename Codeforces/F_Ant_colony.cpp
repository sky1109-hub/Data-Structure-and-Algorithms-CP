// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// class segment
// {
// public:
//     vector<ll> seg, a, minm;
//     int n;
//     segement(int x, vector<int> &xt)
//     {
//         xt = a;
//         n = x;
//         seg.resize(4 * n);
//         minm.resize(4 * n);
//     }
//     void build(int idx, int l, int r)
//     {
//         if (l == r)
//         {
//             seg[idx] = a[l];
//             minm[idx] = a[l];

//             return;
//         }
//         int m = l + (r - l) / 2;
//         build(2 * idx + 1, l, m);
//         build(2 * idx + 2, m + 1, r);
//         seg[idx] = gcd(seg[2 * idx + 1], seg[2 * idx + 2]);
//         minm[idx] = min(minm[2 * idx + 1], minm[2 * idx + 2]);
//     }
//     ll querygcd(int idx, int l, int r, int ql, int qr)
//     {
//         if (ql > r || qr < l)
//             return 0;
//         if (ql <= l && qr >= r)
//             return seg[idx];
//         int m = l + (r - l) / 2;
//         ll x = query(2 * idx + 1, l, m, ql, qr);
//         ll y = query(2 * idx + 2, m + 1, r, ql, qr);
//         return gcd(x, y);
//     }
//     ll queryminm(int idx, int l, int r, int ql, int qr)
//     {
//         if (ql > r || qr < l)
//             return INT_MAX;
//         if (ql <= l && qr >= r)
//             return seg[idx];
//         int m = l + (r - l) / 2;
//         ll x = query(2 * idx + 1, l, m, ql, qr);
//         ll y = query(2 * idx + 2, m + 1, r, ql, qr);
//         return minm(x, y);
//     }
//     int query(int node, int l, int r, int ql, int qr, int x) const {
//         if (qr < l || r < ql)
//             return 0;

//         if (ql <= l && r <= qr) {
//             return upper_bound(seg[node].begin(), seg[node].end(), x)
//                  - lower_bound(seg[node].begin(), seg[node].end(), x);
//         }

//         int mid = (l + r) / 2;
//         return query(2 * node, l, mid, ql, qr, x) +
//                query(2 * node + 1, mid + 1, r, ql, qr, x);
//     }
// };
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     segment s(n, a);
//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int l, int r;
//         cin >> l >> r;
//         l--, r--;
//         ll x = s.querygcd(0, 0, n - 1, l, r);
//         ll y = s.query(0, 0, n - 1, l, r);
//         for (int i = l; i <= r; i++)
//         {
//         }
//     }

//     return 0;
// }
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
