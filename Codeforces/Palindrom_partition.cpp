#include <bits/stdc++.h>
using namespace std;

bool ispal(string s) {
    string k = s;
    reverse(k.begin(), k.end());
    return (k == s && s.size() % 2 == 0); // even length palindrome
}

int solve(int idx, string s, int n) {
    if (idx == n) return 0;
    int ans = 0;
    string temp = "";
    for (int i = idx; i < n; i++) {
        temp += s[i];
        if (ispal(temp)) {
            ans += 1;  // count this palindrome
        }
    }
    return ans + solve(idx + 1, s, n); // continue from next index
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        cout <<"ans:"<< solve(0, s, n) << "\n";
    }
    return 0;
}
