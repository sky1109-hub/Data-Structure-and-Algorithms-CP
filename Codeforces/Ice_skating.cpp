#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class dsu{
    public:
    vector<int>p,size;
    dsu(int x){
        p.resize(x+1);
        iota(p.begin(),p.end(),0);
        size.resize(x+1,0);
    }
    int find(int u){
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void unite(int u,int v){
        u=find(u),v=find(v);
        if(u==v)  return ;
        if(size[u]<size[v]) swap(u,v);
        p[v]=u;
        size[u]+=size[v];

    }

};
int main(){
    int n; cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    } dsu ds(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].first==a[j].first||a[i].second==a[j].second){
                ds.unite(i,j);
            }
        }
    } int c=0;
    for(int i=0;i<n;i++){
        if(ds.find(i)==i)  c++;
    }
    cout<<c-1;

return 0;
}