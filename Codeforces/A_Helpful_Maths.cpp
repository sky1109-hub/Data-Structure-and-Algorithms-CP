#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    string temp;
    vector<int> ans;

    while (getline(ss, temp, '+')) {
        ans.push_back(stoi(temp));
    }

    sort(ans.begin(), ans.end());

  
    string result;
    for (int i = 0; i < (int)ans.size(); i++) {
        result += to_string(ans[i]);
        if (i != ans.size() - 1)
            result += '+';
    }

    cout << result;
    return 0;
}
