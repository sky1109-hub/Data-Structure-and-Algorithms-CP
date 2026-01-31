#include <bits/stdc++.h>
using namespace std;
/// 0-based indexing
class SparseTable {
    vector<vector<int>> st;
    vector<int> arr;
    int n, k;

public:
    SparseTable(vector<int> &a) {
        n = a.size();
        k = __lg(n) + 1;
        arr = a;
        st.assign(n, vector<int>(k));

        // base case
        for (int i = 0; i < n; i++)
            st[i][0] = arr[i];

        build();
    }

    void build() {
        for (int j = 1; j < k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    int query(int l, int r) {
        int j = __lg(r - l + 1);
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int main() {
    vector<int> arr = {2, 5, 1, 4, 9, 3};
    SparseTable st(arr);

    cout << st.query(1, 4) << "\n"; // expected 1
    cout << st.query(0, 2) << "\n"; // expected 1
    cout << st.query(3, 5) << "\n"; // expected 3
}
