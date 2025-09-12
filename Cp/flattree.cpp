#include <bits/stdc++.h>
using namespace std;

vector<int> tree, st, et;
int timer = 1;

void flat_tree(vector<vector<int>>& t, int node, int par) {
    st[node] = timer++;      
    tree.push_back(node);    

    for (auto it : t[node]) {
        if (it != par) {
            flat_tree(t, it, node);
             tree.push_back(node); 
               timer++;
          
            
        }
    }
        
    et[node] = timer;        
}

int main() {
    int n;
    cin >> n;
    st.resize(n + 1);
    et.resize(n + 1);
    vector<vector<int>> t(n + 1);

    for (int i = 0; i < n - 1; i++) { 
        int a, b;
        cin >> a >> b;
        t[a].push_back(b);
        
    }

    flat_tree(t, 1, -1);

    cout << "Flat tree: ";
    for (auto it : tree) cout << it << " ";
    cout << "\n";

    cout << "Start Time: ";
    for (int i = 1; i <= n; i++) cout << st[i] << " ";
    cout << "\n";

    cout << "End Time: ";
    for (int i = 1; i <= n; i++) cout << et[i] << " ";
    cout << "\n";

    return 0;
}
