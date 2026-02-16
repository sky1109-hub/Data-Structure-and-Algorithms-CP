#include <bits/stdc++.h>
using namespace std;

long long sum_of_diffs(vector<long long> &v) {
    sort(v.begin(), v.end());
    long long n = v.size();
    long long sum = 0;
    for(long long i = 0; i < n; i++) {
        sum += v[i] * (2*i - n + 1);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> x(n), y(n);

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    long long ans = sum_of_diffs(x) + sum_of_diffs(y);
    cout << ans << "\n";
}
