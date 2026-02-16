#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class dsu{
    public:
    vector<int> p,rank;
    dsu(int x){
        p.resize(x);
        iota(p.begin(),p.end(),0);
        rank.resize(x,1);
    }
    int find(int x){
        if(p[x]==x)  return x;
        return p[x]=find(p[x]);
    }
    void unite(int x,int y){
        int px=find(x),py=find(y);
        if(px==py)  return ;
        if(rank[px]==rank[py]) {
            p[py]=px;
            rank[px]++;

        }else if(rank[px]>rank[py]){
            p[py]=px;
        }else{
             p[px]=py;
        }
    }

};
int main(){
ll t; cin>>t;
while(t--){
   int n,m;
   cin>>n>>m;
   dsu ds(n+1);
   vector<vector<int>>adj(n+1) ;
   for(int i=0;i<m;i++){
    int x,y,z; cin>>x>>y>>z;//x==1?directed:undire
    if(x){
        adj[y].push_back(z);
        ds.unite(x,y);
    }else{
        if(ds.find(x)==ds.find(y)){
            
        }

   
    }
    
   }
}
return 0;
}