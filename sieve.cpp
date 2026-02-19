#include <bits/stdc++.h>
using namespace std;

vector<bool> p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    p.resize(n + 1, true);
    p[0] = p[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (p[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                p[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (p[i])
            cout << i << " ";
    }

    return 0;
}
