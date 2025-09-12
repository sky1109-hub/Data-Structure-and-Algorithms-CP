#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solvetab(vector<int>& c, int x) {
    int n = c.size();
    vector<int> dp(x + 1, INT_MAX); // Only need size x+1, not n+1
    dp[0] = 0; // Base case: 0 coins needed for amount 0

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0 && dp[i - c[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - c[j]]);
            }
        }
    }

    return dp[x] == INT_MAX ? -1 : dp[x]; // If no combination found
}

int main() {
    int n;
    cout << "Enter number of coins: ";
    cin >> n;
    
    vector<int> c(n);
    cout << "Enter coin denominations:\n";
    for (int i = 0; i < n; i++) { // Fixed input loop
        cin >> c[i];
    }

    int x;
    cout << "Enter amount: ";
    cin >> x;

    int result = solvetab(c, x);
    if (result == -1) {
        cout << "No combination of coins can make up the amount.\n";
    } else {
        cout << "Minimum coins needed: " << result << endl;
    }

    return 0;
}
