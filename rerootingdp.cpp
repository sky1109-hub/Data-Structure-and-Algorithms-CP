// #include <iostream>
// #include <vector>
// using namespace std;

// class Tree {
// public:
//     int n;
//     vector<vector<int>> adj;
//     vector<int> subtreeSize, dp;

//     Tree(int nodes) {
//         n = nodes;
//         adj.resize(n + 1);
//         subtreeSize.resize(n + 1, 1);  // Each node has at least itself
//         dp.resize(n + 1, 0);
//     }

//     void addEdge(int u, int v) {
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     // Step 1: First DFS (calculate subtree sizes and dp[1])
//     void dfs1(int node, int parent) {
//         for (int child : adj[node]) {
//             if (child != parent) {
//                 dfs1(child, node);
//                 subtreeSize[node] += subtreeSize[child];  // Subtree size accumulation
//                 dp[node] += dp[child] + subtreeSize[child];  // DP formula
//             }
//         }
//     }

//     // Step 2: Second DFS (Rerooting)
//     void dfs2(int node, int parent) {
//         for (int child : adj[node]) {
//             if (child != parent) {
//                 // Adjust dp[child] using dp[node]
//                 dp[child] = dp[node] - subtreeSize[child] + (n - subtreeSize[child]);

//                 dfs2(child, node);
//             }
//         }
//     }

//     void calculateDistances() {
//         dfs1(1, -1);  // Compute dp[root]
//         dfs2(1, -1);  // Rerooting to calculate dp for all nodes

//         for (int i = 1; i <= n; i++) {
//             cout << "Sum of distances from node " << i << " = " << dp[i] << endl;
//         }
//     }
// };

// int main() {
//     int nodes = 6;
//     Tree tree(nodes);

//     tree.addEdge(1, 2);
//     tree.addEdge(1, 3);
//     tree.addEdge(2, 4);
//     tree.addEdge(2, 5);
//     tree.addEdge(3, 6);

//     tree.calculateDistances();

//     return 0;
// }
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> adj[100011];
vector< pair<ll,ll> > dp(1e5+11);
vector< pair<ll,ll> > pardp(1e5+11);

void dfs1(ll src, ll par){
    ll maxOfAllChildMaximum = 0, smaxOfAllChildMaximum = 0;
    for(auto itr: adj[src]){
        if(itr==par) continue;
        dfs1(itr, src);
        ll childMax = dp[itr].first;
        if(childMax>=maxOfAllChildMaximum){
            smaxOfAllChildMaximum = maxOfAllChildMaximum;
            maxOfAllChildMaximum = childMax;
        }
        else if(childMax>smaxOfAllChildMaximum){
            smaxOfAllChildMaximum = childMax;
        }
    }
    dp[src]={maxOfAllChildMaximum+1, smaxOfAllChildMaximum+1};
}

void dfs2(ll src, ll par){
    if(src==1){
        pardp[src]=dp[src];
    }
    else{
        ll maxOfAllChildMaximum = dp[src].first - 1, smaxOfAllChildMaximum = dp[src].second - 1;
        ll parentContribution = 0;
        if(dp[src].first+1 == pardp[par].first) parentContribution = pardp[par].second;
        else parentContribution = pardp[par].first;

        if(parentContribution>=maxOfAllChildMaximum){
            smaxOfAllChildMaximum = maxOfAllChildMaximum;
            maxOfAllChildMaximum = parentContribution;
        }
        else if(parentContribution > smaxOfAllChildMaximum){
            smaxOfAllChildMaximum = parentContribution;
        }
        pardp[src]={maxOfAllChildMaximum+1, smaxOfAllChildMaximum+1};
    }
    for(auto itr: adj[src]){
        if(itr==par) continue;
        dfs2(itr, src);
    }
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n; cin>>n;
    for(ll i=0;i<n-1;i++){
        ll x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    for(ll i=1;i<=n;i++){
        cout<<dp[i].first<<" "<<dp[i].second<<endl;
    }
    cout<<"-----"<<endl;
    for(ll i=1;i<=n;i++){
        cout<<pardp[i].first<<" ";
    }
    cout<<endl;
}

