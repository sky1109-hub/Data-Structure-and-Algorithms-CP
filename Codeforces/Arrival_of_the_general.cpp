#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int c = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
      

     for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
                c++;
            }
        }
     }   
   if(c>n)  cout<<c-n;
   else cout<<c;
    return 0;
}