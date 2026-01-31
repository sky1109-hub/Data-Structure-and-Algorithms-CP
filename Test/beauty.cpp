#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<int> val;
vector<vector<int>> adj;
int free(int x)
{
    int res = 1;
    for (int i = 2; i * i <= x; i++)
    {
        int c = 0;
        while (x % i == 0)
        {
            c++;
            x /= i;
        }
        if (c & 1)
            res *= i;
    }
    if (x > 1)
        res *= x;
    return res;
}
unordered_map<int, vector<int>> leaf;
void dfs(int u, int p,unordered_map<int,int>&m1)
{
    
}
int main()
{
    cin >> n;
    adj.resize(n + 1);
    val.resize(n + 1);
    //vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            continue;
        int x;
        xin >> x;
        adj[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> val[i];
     dfs(1,-1);  
    for(auto it:mp){
        int p=it.second;
        vector<int>l=it.second;
        for(auto it:l){

        }
    }  

    return 0;
}