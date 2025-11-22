#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class SegTree {
public:
    int n;
    vector<ll> tree;

    SegTree(int n) : n(n) {
        tree.assign(4 * n, 0);
    }

    void update(int idx, int l, int r, int pos, ll val) {
        if (l == r) {
            tree[idx] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(idx * 2, l, mid, pos, val);
        else
            update(idx * 2 + 1, mid + 1, r, pos, val);

        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }

    ll query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        return query(idx * 2, l, mid, ql, qr) +
               query(idx * 2 + 1, mid + 1, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Step 1: Compute left frequencies
    unordered_map<ll, int> freq;
    vector<int> leftFreq(n), rightFreq(n);

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        leftFreq[i] = freq[a[i]];
    }

    // Step 2: Compute right frequencies
    freq.clear();
    for (int i = n - 1; i >= 0; i--) {
        freq[a[i]]++;
        rightFreq[i] = freq[a[i]];
    }

    
    SegTree st(n);

    // Insert rightFreq[j] for j = 1..n-1
    for (int j = 1; j < n; j++) {
        st.update(1, 1, n, rightFreq[j], 1);
    }

    ll ans = 0;

    // Step 3: sweep i from 0..n-2
    for (int i = 0; i < n - 1; i++) {
        int lf = leftFreq[i];

        // Count all j > i with rightFreq[j] < leftFreq[i]
        if (lf > 1) {
            ans += st.query(1, 1, n, 1, lf - 1);
        }

        // Remove the j = i+1 element from segment tree
        st.update(1, 1, n, rightFreq[i + 1], -1);
    }

    cout << ans << "\n";
    return 0;
}
