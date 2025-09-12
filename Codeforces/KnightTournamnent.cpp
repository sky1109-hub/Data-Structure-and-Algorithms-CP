#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int res[N];       
int next_alive[N]; 

int find_next(int i) {
    
    if (next_alive[i] != i)
        next_alive[i] = find_next(next_alive[i]);
    return next_alive[i];
}

int main() {
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n + 1; i++) {
        next_alive[i] = i;
    }

    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;

        int i = find_next(l);
        while (i <= r) {
            if (i != x) {
                res[i] = x;
                next_alive[i] = i + 1; 
            }
            i = find_next(i + 1);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}
