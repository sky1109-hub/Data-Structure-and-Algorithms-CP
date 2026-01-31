// #include <bits/stdc++.h>
// using namespace std;

// const int MAX = (1 << 17);
// vector<int> seg(4 * MAX);
// vector<int> arr;

// void build(int idx, int l, int r, int op) {
//     if (l == r) {
//         seg[idx] = arr[l];
//         return;
//     }

//     int mid = (l + r) / 2;
//     build(2 * idx + 1, l, mid, !op);
//     build(2 * idx + 2, mid + 1, r, !op);

//     if (op)
//         seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
//     else
//         seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
// }

// void update(int idx, int l, int r, int pos, int val, int op) {
//     if (l == r) {
//         seg[idx] = val;
//         return;
//     }

//     int mid = (l + r) / 2;
//     if (pos <= mid)
//         update(2 * idx + 1, l, mid, pos, val, !op);
//     else
//         update(2 * idx + 2, mid + 1, r, pos, val, !op);

//     if (op)
//         seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
//     else
//         seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     int size = 1 << n;
//     arr.resize(size);

//     for (int i = 0; i < size; ++i)
//         cin >> arr[i];

//     // n&1 == 1 --> OR at root
//     build(0, 0, size - 1, n % 2);

//     while (m--) {
//         int p, b;
//         cin >> p >> b;
//         --p;  // 0-based indexing
//         update(0, 0, size - 1, p, b, n % 2);
//         cout << seg[0] << "\n";
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> seg;
    int n, height;

    SegmentTree(int n, vector<int> &a) : n(n) {
        seg.resize(4 * n);
        height = __lg(n);   
        build(0, 0, n - 1, a, height % 2);
    }

    void build(int idx, int l, int r, vector<int> &a, int op) {
        if (l == r) {
            seg[idx] = a[l];
            return;
        }
        int m = (l + r) >> 1;

        build(idx*2 + 1, l, m, a, op ^ 1);
        build(idx*2 + 2, m + 1, r, a, op ^ 1);

        if (op == 1) seg[idx] = seg[idx*2 + 1] | seg[idx*2 + 2];
        else seg[idx] = seg[idx*2 + 1] ^ seg[idx*2 + 2];
    }

    void update(int idx, int l, int r, int pos, int val, int op) {
        if (l == r) {
            seg[idx] = val;
            return;
        }

        int m = (l + r) >> 1;

        if (pos <= m)
            update(idx*2 + 1, l, m, pos, val, op ^ 1);
        else
            update(idx*2 + 2, m + 1, r, pos, val, op ^ 1);

        if (op == 1) seg[idx] = seg[idx*2 + 1] | seg[idx*2 + 2];
        else         seg[idx] = seg[idx*2 + 1] ^ seg[idx*2 + 2];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, m;
    cin >> k >> m;

    int n = 1 << k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree st(n, a);

    while (m--) {
        int p, b;
        cin >> p >> b;
        st.update(0, 0, n - 1, p - 1, b, st.height % 2);
        cout << st.seg[0] << "\n";
    }

    return 0;
}
