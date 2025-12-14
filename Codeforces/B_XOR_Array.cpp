#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        int c = 0;
        bool flag = false;
        for (int i = l; i <= r; i++)
        {
            for (int j = i; j <= r; j++)
            {
                if ((i ^ j))
                {
                    cout << i <<" ";
                    c++;
                    if (c == n)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
            {
                cout << "\n";
                break;
            }
        }
    }
    return 0;
}