#include <bits/stdc++.h>
using namespace std;
int main(){
 vector<int>a(3);
 for(int i=0;i<3;i++)  cin>>a[i];
 sort(a.begin(),a.end());
 int mid=((a[2]-a[0])/2)+a[0];
 cout<<abs(a[2]-mid)+abs(a[1]-mid)+abs(a[0]-mid)<<endl;
return 0;
}