#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    int p = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        p += (b - a);
        ans = max(ans, p);
    }
    cout << ans << endl;
    return 0;
}