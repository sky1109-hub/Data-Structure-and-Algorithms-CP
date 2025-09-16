#include <bits/stdc++.h>
using namespace std;
int solve(int n, int cs)
{
    if (cs > n)
        return 0;
    if (cs == n)
        return 1;
    int s = 0;
    for (int i = 1; i <= min(6, n); i++)
    {
        s += solve(n, cs + i);
    }
    return s;
}
int main()
{

    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    cout << solve(n, 0) << endl;
    return 0;
}