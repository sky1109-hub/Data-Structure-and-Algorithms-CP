#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class disjoint
{
    int n;
    vector<int> par, size;

public:
    disjoint(int k)
    {
        n = k;
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        size.resize(n + 1, 1);
    }

    int find(int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = find(par[u]);
    }

    bool unite(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;

        if (size[u] < size[v])
            swap(u, v);
        par[v] = u;
        size[u] += size[v];
        return true;
    }
};

int main()
{
    int n;
    cin >> n;

    disjoint ds(n);

    int t = n - 1;
    vector<array<int, 4>> ans;

    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (!ds.unite(x, y))
        {
            ans.push_back({x, y, 0, 0});
        }
    }

    vector<int> d;
    int comp = 0;
  

    for (int i = 1; i <= n; i++)
    {
        if (ds.find(i) == i)
        {
            d.push_back(i);
           
        }
    }
       cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "
        <<d[i]<<" "<<d[i+1]<<" "<<endl;
    }

    
    
    return 0;
}
