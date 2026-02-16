#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<int> a;

int main()
{
    cin >> n >> m;
    a.resize(n);
    vector<int> dp(m, -1);

    // for (int i = 0; i < n; i++)
    //     cin >> a[i];

    for (int i = 0; i < n; i++)
    {
         cin >> a[i];
        int x = a[i] % m;

        for(int j=0;j<m;j++){
            if(dp[j]!=-1&&dp[j]<i){
              if(dp[(j+a[i])%m]==-1)  dp[(j+a[i])%m]=i;
            }
        } 
   if(dp[x]==-1)  dp[x]=i;
    }

    cout << (dp[0] != -1 ? "YES\n" : "NO\n");

    return 0;
}
