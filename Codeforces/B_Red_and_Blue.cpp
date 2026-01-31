#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p1 = 0, p2 = 0;
        vector<int> a(n), p(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            p[i+1] = p[i] + a[i];
            p1 = max(p1, p[i+1]);
        }
        int m;
        cin >> m;
        vector<int> b(m), px(m + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            px[i+1] = px[i] + b[i];
            p2 = max(p2, px[i+1]);
        }
        cout<<p1+p2<<endl;
    }
    return 0;
}