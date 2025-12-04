#include <bits/stdc++.h>
using namespace std;

struct LazySegTree {
    int n;
    vector<long long> tree, lazy;

    LazySegTree(int n) {
        this->n = n;
        tree.assign(4*n, 0LL);
        lazy.assign(4*n, 0LL);
    }

    // Build from array (0-based)
    void build(vector<long long> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;

        int left  = 2*node + 1;
        int right = 2*node + 2;

        build(arr, left, start, mid);
        build(arr, right, mid+1, end);

        tree[node] = tree[left] + tree[right];
    }

    // Push pending lazy update to children
    void pushDown(int node, int start, int end) {
        if (lazy[node] == 0) return;

        long long val = lazy[node];
        int mid = (start + end) / 2;

        int left  = 2*node + 1;
        int right = 2*node + 2;

        // Left child
        tree[left] += val * (mid - start + 1);
        lazy[left] += val;

        // Right child
        tree[right] += val * (end - mid);
        lazy[right] += val;

        lazy[node] = 0;  // clear
    }

    // Range add: add v to every element in [l, r]
    void updateRange(int node, int start, int end, int l, int r, long long v) {
        if (r < start || end < l) return;  // no overlap

        if (l <= start && end <= r) {       // full overlap
            tree[node] += v * (end - start + 1);
            lazy[node] += v;
            return;
        }

        pushDown(node, start, end);

        int mid = (start + end) / 2;
        int left  = 2*node + 1;
        int right = 2*node + 2;

        updateRange(left, start, mid, l, r, v);
        updateRange(right, mid+1, end, l, r, v);

        tree[node] = tree[left] + tree[right];
    }

    // Point update: arr[idx] = new_value
    void updatePoint(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        pushDown(node, start, end);

        int mid = (start + end) / 2;
        int left  = 2*node + 1;
        int right = 2*node + 2;

        if (idx <= mid)
            updatePoint(left, start, mid, idx, val);
        else
            updatePoint(right, mid+1, end, idx, val);

        tree[node] = tree[left] + tree[right];
    }

    // Range sum query
    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;

        if (l <= start && end <= r)
            return tree[node];

        pushDown(node, start, end);

        int mid = (start + end) / 2;
        int left  = 2*node + 1;
        int right = 2*node + 2;

        return query(left, start, mid, l, r)
             + query(right, mid+1, end, l, r);
    }
};
