#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int cnt47 = 0, cnt74 = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '4' && b[i] == '7') cnt47++;
        if (a[i] == '7' && b[i] == '4') cnt74++;
    }
    cout << max(cnt47, cnt74) << "\n";
    return 0;
}
