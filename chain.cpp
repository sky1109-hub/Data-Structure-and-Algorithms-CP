#include <iostream>
#include <vector>
#include <algorithm> // for find()
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> w(n), p(n + 1, 0);

    // Input weights
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    // Compute prefix sum array
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + w[i];
    }

    // Check if we can partition into two equal subsets
    for (int i = 0; i < n; i++) {
        int totalSum = p[n] - w[i]; // Sum of elements excluding w[i]
        int target = totalSum / 2;

        // Check if target + w[i] exists in prefix sum
        auto it = find(p.begin(), p.end(), target + w[i]);
        if (it != p.end()) {
            cout << "true";
            return 0; // Exit after finding a valid partition
        }
    }

    cout << "false";
    return 0;
}
