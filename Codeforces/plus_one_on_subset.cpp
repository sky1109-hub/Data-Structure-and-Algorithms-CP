#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, maxi = INT_MIN, mini = INT_MAX;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            maxi = max(maxi, a[i]);
            mini = min(mini, a[i]);
        }
        cout << maxi - mini << endl;
    }
    return 0;
}