#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct DSU {
    vector<int> par, sz;
    DSU(int n) {
        par.resize(n);
        sz.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
};

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> top(n), bottom(n);
        for (int i = 0; i < n; i++) cin >> top[i];
        for (int i = 0; i < n; i++) cin >> bottom[i];

        vector<int> pos1(n+1), pos2(n+1);
        for (int i = 0; i < n; i++) {
            pos1[top[i]] = i;      // number top[i] is in column i
            pos2[bottom[i]] = i;   // number bottom[i] is in column i
        }

        DSU dsu(n);

        for (int x = 1; x <= n; x++) {
            dsu.unite(pos1[x], pos2[x]);
        }

        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i)
                cycles++;
        }

        cout << power(2, cycles) % MOD << "\n";
    }

    return 0;
}
