#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n * t + 1);
    for (size_t i = 1; i <= n; i++)

    {
        cin >> a[i];
    } for(int i=n+1;i<=n*t;i++){
        a[i]=a[i-n];
    }
     vector<int>ans;
     for(auto it:a){
        auto it2=lower_bound(ans.begin(),ans.end(),it);
        if(it2==ans.end()){
            ans.push_back(it);
        }else{
            *it2=it;
        }
        
    }  cout<<ans.size();

    return 0;
}