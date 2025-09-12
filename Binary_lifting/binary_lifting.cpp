#include <bits/stdc++.h>
using namespace std;

class bl {
public:
    vector<vector<int>> v;
    vector<int> p;
    int k = 17;

    bl(vector<int>& a) {
        p = a;
        int n = a.size();
        v.resize(k, vector<int>(n, -1));
        build(n);
    }

    void build(int n) {
        // 0th ancestor = immediate parent
        for (int i = 0; i < n; i++) {
            v[0][i] = p[i];
        }

        // fill binary lifting table
        for (int j = 1; j < k; j++) {
            for (int i = 0; i < n; i++) {
                if (v[j - 1][i] == -1) v[j][i] = -1;
                else v[j][i] = v[j - 1][v[j - 1][i]];
            }
        }
    }

    int query(int node, int kth) {
        for (int j = 0; j < k; j++) {   // <k, not <=k
            if ((kth >> j) & 1) {
                node = v[j][node];     // v[j][node], not v[node][j]
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> parent(n);
    for (int i = 0; i < n; i++) cin >> parent[i];  // parent[i] = -1 for root

    bl tree(parent);

    int q;
    cin >> q;
    while (q--) {
        int node, k;
        cin >> node >> k;
        cout << tree.query(node, k) << "\n";
    }
    return 0;
}
