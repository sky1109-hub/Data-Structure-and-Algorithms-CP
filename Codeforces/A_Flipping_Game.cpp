#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) ones++;
    }

    int best = -1e9, curr = 0;

    for (int x : a) {
        int val = (x == 0 ? 1 : -1);   
        curr = max(val, curr + val);
        best = max(best, curr);
    }

    
    if (ones == n) {
        cout << n - 1;
    } else {
        cout << ones + best;
    }
}
