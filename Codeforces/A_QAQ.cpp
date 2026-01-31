#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// method 1:
// int solve(int i1,int i2,string s,string p){
//     if(i2==0)  return 1;
//     if(i1==0)  return (i2==0?1:0);
//     int c1=0,c2=0,c3=0;
//     if(s[i1-1]==p[i2-1]){
//         c1=solve(i1-1,i2-1,s,p);
//         c2=solve(i1-1,i2,s,p);
//     }else {
//         c3=solve(i1-1,i2,s,p);
//     }
//     return c1+c2+c3;
// }
int main()
{
    string s, p = "QAQ";
    cin >> s;
    int n = s.size(), m = 3;
    // cout<<solve(s.size(),3,s,"QAQ");

    //
    // vector<vector<int>> dp(n + 1, vector<int>(4, 0));
    // for (int i = 0; i <= n; i++)
    //     dp[i][0] = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= 3; j++)
    //     {
    //         if (s[i - 1] == p[j - 1])
    //         {
    //             dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    //         }
    //         else
    //         {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //     }
    // }
    // cout << dp[n][3];
    int 

    return 0;
}