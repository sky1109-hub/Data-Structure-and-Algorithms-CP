#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int imin = min_element(a.begin(), a.end()) - a.begin();
        int imax = max_element(a.begin(), a.end()) - a.begin();
        
        if (imin > imax) swap(imin, imax); 
        
        int fromLeft = imax + 1;                
        int fromRight = n - imin;               
        int bothSides = (imin + 1) + (n - imax); 
        
        cout << min({fromLeft, fromRight, bothSides}) << "\n";
    }
    return 0;
}
