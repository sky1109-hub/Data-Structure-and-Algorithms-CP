#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> mp;  // adjacency list
unordered_map<string, int> vis;           // visited for DFS
vector<string> topo;                      // topological order

void dfs(const string &u) {
    vis[u] = 1;
    for (const auto &v : mp[u]) {
        if (!vis[v]) dfs(v);
    }
    topo.push_back(u);  }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s1, x, s2;
        cin >> s1 >> x >> s2;

       
        for (auto &ch : s1) if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
        for (auto &ch : s2) if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';

        mp[s1].push_back(s2);
    }

 // algo: step1: toposort
 
    for (auto &p : mp) {
        if (!vis[p.first]) dfs(p.first);
    }

    reverse(topo.begin(), topo.end());

    
    unordered_map<string, int> dist;

    
    for (auto &p : mp) dist[p.first] = INT_MIN;

    
    unordered_map<string, int> indeg;
    for (auto &p : mp) {
        indeg[p.first]; 
        for (auto &v : p.second) indeg[v]++;
    }

    for (auto &p : indeg)
        if (p.second == 0) dist[p.first] = 0;

    
    for (const string &u : topo) {
        if (dist[u] == INT_MIN) dist[u] = 0; 
        for (const string &v : mp[u]) {
            dist[v] = max(dist[v], dist[u] + 1);
        }
    }

    
    int best = 0;
    for (auto &p : dist) best = max(best, p.second);

    cout << best+1 << "\n";
    return 0;
}
