#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        vector<int> a(n+1);
        k=n;

        for(int j=1;j<=n;j++)
            cin >> a[j];

        int z1 = 0, z2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] - i == 0)
                z1++;
            if (a[i] - (n - i + 1)== 0)
                z2++;
        }
        if (z1 == n || z2 == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}