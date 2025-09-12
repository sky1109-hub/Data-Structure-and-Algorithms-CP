#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for (int i = 0; i < (int)s.size(); ++i) {
        int d = s[i] - '0';
        int inv = 9 - d;

        if (i == 0 && s[i] == '9') continue;

        if (inv < d) s[i] = char('0' + inv);
    }

    cout << s << "\n";
    return 0;
}
