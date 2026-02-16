#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int h=0;
int find_dist(int h){
    int k=0;
    for(int i=0;i<h;i++){
        if(s1[i]!=s2[i]) k++;
    }
    return k;
}
int main(){
   int n,m;
   cin>>n>>m;
   
    cin>>s1>>s2;

   int n1=s1.size(),n2=s2.size();
     if(n1*n!=n2*m){
        cout<<0<<endl;
        return 0;
     }
    h=n2*m;
    int x=find_dist(h);
     cout<<x<<endl;
return 0;
}