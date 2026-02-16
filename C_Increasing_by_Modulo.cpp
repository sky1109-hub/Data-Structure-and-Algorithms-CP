#include <bits/stdc++.h>
using namespace std;

bool can(int T, vector<int> &a, int m)
{
    int prev = 0;

    for (int x : a)
    {
        if (x + T < m)
        {
            if (prev > x + T)
                return false;
            prev = max(prev, x);
        }
        else
        {
            int maxReach = (x + T) % m;
            if (prev > maxReach && prev < x)
                prev = x;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int low = 0, high = m, ans = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (can(mid, a, m))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}
