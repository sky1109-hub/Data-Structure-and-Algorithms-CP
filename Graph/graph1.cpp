#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
class graph{
    public:
    unordered_map<int,list<int>>m;
     void addedge(int u,int v,bool dir){
        //0:undirected 1: directed
        m[u].push_back(v);
        if(dir==0){
            m[v].push_back(u);

        }
     }
     void printg(){
        for(auto it:m){
            cout<<it.first <<"-> ";
            for(auto k:it.second){
               cout<<k<<" ,";
            }
            cout<<endl;
        }
     }
};
int main(){
    graph g;
    int m,n;
// cout<<"Enter no. of node";
// cin>>n;
cout<<"Enter no of  edge";
cin>>m;
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    g.addedge(u,v,0);
}
g.printg();

return 0;
}