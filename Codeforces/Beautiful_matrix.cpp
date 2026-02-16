#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[5][5];
    int mc=2,mr=2,nr,nc;
    for(int i=0;i<5 ;i++){
        for(int j=0;j<5;j++){
           cin>>a[i][j];
           if(a[i][j]){
             nr=i,nc=j;
           }

        }
    }
        cout<<abs(mc-nc)+abs(mr-nr)<<endl;
return 0;
}