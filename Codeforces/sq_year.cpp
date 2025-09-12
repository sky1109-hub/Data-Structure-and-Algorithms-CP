#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int a = stoi(s.substr(0, 2)); 
        int b = stoi(s.substr(2, 2));
        int year = stoi(s);
        if ((a + b) * (a + b) == year)
            cout << a << " " << b << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}
