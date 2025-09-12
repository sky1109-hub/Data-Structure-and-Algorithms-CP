#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<long long> tree, lazy;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void build(vector<long long> &arr, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, idx * 2, l, mid);
        build(arr, idx * 2 + 1, mid + 1, r);
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
    }

    void pushDown(int idx) {
        if (lazy[idx] != 0) {
            tree[idx * 2] += lazy[idx];
            lazy[idx * 2] += lazy[idx];

            tree[idx * 2 + 1] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];

            lazy[idx] = 0;
        }
    }

    void update(int idx, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return; // no overlap
        if (ql <= l && r <= qr) { // total overlap
            tree[idx] += val;
            lazy[idx] += val;
            return;
        }
        pushDown(idx);
        int mid = (l + r) / 2;
        update(idx * 2, l, mid, ql, qr, val);
        update(idx * 2 + 1, mid + 1, r, ql, qr, val);
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return LLONG_MAX; // no overlap
        if (ql <= l && r <= qr) return tree[idx]; // total overlap
        pushDown(idx);
        int mid = (l + r) / 2;
        return min(query(idx * 2, l, mid, ql, qr),
                   query(idx * 2 + 1, mid + 1, r, ql, qr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree seg(n);
    seg.build(arr, 1, 0, n - 1);

    int m;
    cin >> m;
    while (m--) {
        string line;
        getline(cin, line);
        if (line.empty()) {
            m++;
            continue;
        }
        stringstream ss(line);
        vector<long long> nums;
        long long x;
        while (ss >> x) nums.push_back(x);

        if (nums.size() == 2) {
            int l = nums[0], r = nums[1];
            if (l <= r) {
                cout << seg.query(1, 0, n - 1, l, r) << "\n";
            } else { // circular range
                cout << min(seg.query(1, 0, n - 1, l, n - 1),
                            seg.query(1, 0, n - 1, 0, r)) << "\n";
            }
        } else { // update
            int l = nums[0], r = nums[1];
            long long v = nums[2];
            if (l <= r) {
                seg.update(1, 0, n - 1, l, r, v);
            } else { // circular update
                seg.update(1, 0, n - 1, l, n - 1, v);
                seg.update(1, 0, n - 1, 0, r, v);
            }
        }
    }

    return 0;
}
