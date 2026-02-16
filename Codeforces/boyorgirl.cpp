#include <bits/stdc++.h>
using namespace std;
int main(){
string s;
getline(cin,s);
 map<char,int>m;
 for(auto it:s){
    m[it]++;
 } 
 
 int x=m.size();
 if(x%2==0) cout<<"CHAT WITH HER!"<<endl;
 else cout<< "IGNORE HIM!"<<endl;
return 0;
}