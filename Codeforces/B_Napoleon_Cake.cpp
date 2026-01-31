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
        vector<int> a(n), p(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int cur=0;    
        for (int i = n - 1; i >= 0; i--)
        {   cur=max(cur-1,a[i]);
            if(cur>0) p[i]=1;

        }
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << endl;
    }

    return 0;
}