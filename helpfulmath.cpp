#include <bits/stdc++.h>
using namespace std;
int main(){
   string s;
   getline(cin,s);
   vector<int>ans;
   for(auto it:s){
    if(it>= '1'&& it<='3'){
        ans.push_back(it - '0');
    }
   }  sort(ans.begin(),ans.end());
   s="";
  for(int i=0;i<ans.size();i++){
    s+=to_string(ans[i]);
    if(i!=ans.size()-1) s+="+";
  }
  cout<<s<<endl;;
return 0;
}
