#include <bits/stdc++.h>
using namespace std;
  using ll=long long;

int main() {
    string s;
    cin >> s;
    string x;
    cin >> x;
    int k;
    cin >> k;

    vector<int> good(26, 0);
    for (int i = 0; i < 26; i++) {
        if (x[i] == '1')
            good[i] = 1;
    }
       unordered_map<string,ll>mp;
   // set<string> st;
    ll n = s.size();

    for (int i = 0; i < n; i++) {
        int bad = 0;
        string temp = "";

        for (int j = i; j < n; j++) {
            temp += s[j];

            if (good[s[j] - 'a'] == 0)
                bad++;

            if (bad > k)
                break;

            mp[temp]++;
        }
    }

    cout << mp.size();
    return 0;
}
