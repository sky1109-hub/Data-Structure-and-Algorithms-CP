#include <bits/stdc++.h>
using namespace std;
int main(){
    int  n,m;
    cin>>n>>m;
  
    vector<vector<char>>mat(n,vector<char>(m,'#'));
    int i=1,c=0;
    while(i<n){
        if(c%2==0)  {for(int j=0;j<m-1;j++)  mat[i][j]='.'; }
        else for(int j=1;j<m;j++)  {mat[i][j]='.';};
        c++;
        i+=2;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j];
        } cout<<endl;
    }

return 0;
}