#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

 
    priority_queue<int> pq; 
    for (int i = 0; i < 31; i++) {
        if ((n >> i) & 1) pq.push(1 << i);
    }

   
    if (k < pq.size() || k > n) {
        cout << "NO\n";
        return 0;
    }

    while (pq.size() < k) {
        int top = pq.top(); pq.pop();
        pq.push(top / 2);
        pq.push(top / 2);
    }

    cout << "YES\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}
