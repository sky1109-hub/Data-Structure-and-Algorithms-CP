// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// struct Node
// {
//     vector<Node *> link;
//     int p, c;
//     Node()
//     {
//         link.resize(3, NULL);
//         p = 0, c = 0;
//     }
// };
// class trie
// {
// private:
//     Node *root;

// public:
//     trie()
//     {
//         root = new Node();
//     }
//     void insert(string s)
//     {
//         Node *cur = root;
//         cur->p++;
//         for (auto it : s)
//         {
//             int idx = it - 'a';
//             if (cur->link[idx] == NULL)
//             {
//                 cur->link[idx] = new Node();
//             }
//             cur = cur->link[idx];
//             cur->p++;
//         }
//         cur->c++;
//     }
//     bool check(string s)
//     {
//         int c = 0;
//         Node *cur = root;

//         for (int i = 0; i < s.size(); i++)
//         {
//             int idx = s[i] - 'a';
//             if (cur->link[idx] == NULL)
//             {
               
//                 for (int j = 0; j < 3; j++)
//                 {
//                     if ( cur->link[j] != NULL)
//                     {
//                         bool temp = tc(s.substr(i + 1), cur->link[j]);
//                         if (temp)
//                             return true;
//                     }
//                 }
//             }

//             else
//             {
//                 cur = cur->link[idx];
               
//             }
//         }
//         return false;
//     }
//     bool tc(string s, Node *cur)
//     {
//         for (auto it : s)
//         {
//             int idx = it - 'a';
//             if (cur->link[idx])
//                 cur = cur->link[idx];
//             else
//                 return false;
//         }
//         return cur->c > 0;
//     }
// };

// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     unordered_map<int, set<string>> mp;
//     trie t;
//     for (int i = 0; i < m; i++)
//     {
//         string s;
//         cin >> s;
//         int x = s.size();
//         mp[x].insert(s);
//         t.insert(s);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         string s;
//         cin >> s;
//         int x = s.size();
//           bool ans = false;

//         if (mp.find(x) != mp.end())
//         {
//            ans=t.check(s);
//         }
//         cout << (ans ? "YES\n" : "NO\n");
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_set<string> st;
    st.reserve(n * 2);
    st.max_load_factor(0.7);

    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        st.insert(s);
    }

    while (m--) {
        cin >> s;
        bool ok = false;

        for (int i = 0; i < (int)s.size() && !ok; i++) {
            char orig = s[i];
            for (char c : {'a', 'b', 'c'}) {
                if (c == orig) continue;
                s[i] = c;
                if (st.find(s) != st.end()) {
                    ok = true;
                    break;
                }
            }
            s[i] = orig;    
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
