#include <bits/stdc++.h>

using namespace std;
int f(int idx,int wt[],int va[],int w,vector<vector<int>>&dp){
    if(idx==0){
        if(wt[0]<=w){
            return (w/wt[0])*va[0];
        } return 0;
    } if(dp[idx][w]!=-1) return dp[idx][w];
    int nt=f(idx-1,wt,va,w,dp);
    int t=0;
    if(wt[idx]<=w) t=va[idx]+f(idx,wt,va,w-wt[idx],dp);
    return  dp[idx][w]=max(t,nt);
}
int main(){
int wt[]={2,4,6};
int va[]={5,11,13};
int w=10;
//vector<vector<int>>dp(3,vector<int>(w+1,-1));  // for memo
vector<vector<int>>dp(3,vector<int>(w+1,0));

//cout<<"max profit: "<< f(2,wt,va,w,dp)<<endl;
// for recursion
//cout<<"max profit: "<< f(2,wt,va,w)<<endl; 
for (int m = wt[0]; m <= w; m++) {
    dp[0][m] = (m / wt[0]) * va[0];
}

for (int i = 1; i < 3; i++) {
    for (int j = 0; j <= w; j++) {
        int nt = dp[i - 1][j]; // not take
        int t = 0;
        if (wt[i] <= j) t = va[i] + dp[i][j - wt[i]]; // take
        dp[i][j] = max(nt, t);
    }
}

cout << "Max profit: " << dp[2][w] << endl;
return 0;
}