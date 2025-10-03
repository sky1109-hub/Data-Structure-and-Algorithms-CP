#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> a;
vector<vector<int>> dp;
  string solve(int i,int j,int n){
    if(i==n-1&&j==n-1){
        return  {a[i][j]};
    }
    string r="~",d="~";
    if(i+1<n){
     d=solve(i+1,j,n);
    }
    if(j+1<n){
        r=solve(i,j+1,n);
    }
    string k=(r<d)?r:d;
    return a[i][j]+k;

    
   
  }
int main()
{
    int n;
    cin >> n;
    a.resize(n, vector<char>(n));
        dp.resize(n, vector<int>(n,0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
   // cout << solve(0,0,n) ;
    return 0;
}