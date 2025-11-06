#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; 
    if (!(cin >> s)) return 0;
    
    string st;
    st.reserve(s.size());
    for (char c : s) {
        if (!st.empty() && st.back() == c) st.pop_back();
        else st.push_back(c);
    }
    cout << (st.empty() ? "YES" : "NO") << '\n';
    return 0;
}
