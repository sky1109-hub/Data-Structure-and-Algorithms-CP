#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums={1,4,2,5,3,50,9,32,45};

    int n=nums.size();
    vector<int>prev(n,-1);
    int maxlen=1,lastidx=0;
 vector<int> dp(n,1);
 for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
        if(nums[j]<nums[i]&& dp[j]+1>dp[i]){
            dp[i]=dp[j]+1;
            prev[i]=j;
        }
    }
    if(dp[i]>maxlen){
        maxlen=dp[i];
        lastidx=i;
    }
 }
  cout<<"Max Len: "<<maxlen<<endl;
 vector<int>LIS;
 for(int i=lastidx;i!=-1;i=prev[i]){
    LIS.push_back(nums[i]);
 }  reverse(LIS.begin(),LIS.end());
 for(int i=0;i<LIS.size();i++){
    cout<<LIS[i];
    if(i!=LIS.size()-1){
        cout<<" -> ";
    }
 }
return 0;
}