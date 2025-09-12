#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, set<int>> mp;

    while (n--) {
        string op;
        int x, y;
        cin >> op >> x >> y;

        if (op == "add") {
            mp[x].insert(y);
        }
        else if (op == "remove") {
            auto it = mp.find(x);
            if (it != mp.end()) {
                it->second.erase(y);
                if (it->second.empty()) {
                    mp.erase(it);
                }
            }
        }
        else if (op == "find") {
            // Find smallest key >= x
            auto it = mp.lower_bound(x);
            bool found = false;

            while (it != mp.end()) {
                auto &st = it->second;
                auto it2 = st.upper_bound(y);  // find value > y in set
                if (it2 != st.end()) {
                    cout << it->first << " " << *it2 << "\n";
                    found = true;
                    break;
                }
                ++it;
            }

            if (!found) cout << -1 << "\n";
        }
    }
    return 0;
}
