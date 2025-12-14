#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<pair<int,int>> juices;   // (cost, mask)

// Pure recursive function WITHOUT memoization
int solve(int mask) {
    if (mask == 7) return 0; // Already have A, B, C

    int ans = INF;

    for (auto &j : juices) {
        int cost = j.first;
        int m = j.second;

        int newMask = mask | m;

        ans = min(ans, cost + solve(newMask));
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int cost;
        string s;
        cin >> cost >> s;

        int mask = 0;
        for (char c : s) {
            if (c == 'A') mask |= 1;
            else if (c == 'B') mask |= 2;
            else if (c == 'C') mask |= 4;
        }

        juices.push_back({cost, mask});
    }

    int ans = solve(0);  // Start with no vitamins

    if (ans >= INF) ans = -1;
    cout << ans;
    return 0;
}
