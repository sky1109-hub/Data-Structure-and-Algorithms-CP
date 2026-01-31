#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> f(26, 0);
        for (char ch : s) f[ch - 'a']++;

        ll oddCount = 0;
        for (int i = 0; i < 26; i++)
            if (f[i] % 2) oddCount++;

        
        if (oddCount <= k + 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
