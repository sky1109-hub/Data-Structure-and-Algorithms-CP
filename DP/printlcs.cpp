#include <bits/stdc++.h>
using namespace std;
int main(){

    string t1="abcdefgh",t2="bdgekfgh";
    int n=t1.size(),m=t2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(t1[i-1]==t2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            } else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string lcs="";
    int i=n,j=m;
    while(i>0&&j>0){
        if(t1[i-1]==t2[j-1]){
            lcs=t1[i-1]+lcs;
            i--;j--;
        } else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        } else j--;
    }
    cout<<"LCS: "<<lcs<<endl;
return 0;
}