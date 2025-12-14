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

        vector<long long> s(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }

        vector<int> dp(n + 1, 1);
        int answer = 1;

        for (int i = 1; i <= n; i++) {
            for (int d = 1; d * d <= i; d++) {
                if (i % d == 0) {
                    int j1 = d;
                    int j2 = i / d;

                    if (j1 < i && s[j1] < s[i])
                        dp[i] = max(dp[i], dp[j1] + 1);

                    if (j2 != j1 && j2 < i && s[j2] < s[i])
                        dp[i] = max(dp[i], dp[j2] + 1);
                }
            }
            answer = max(answer, dp[i]);
        }

        cout << answer << '\n';
    }

    return 0;
}
