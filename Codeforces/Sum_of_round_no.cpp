#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        vector<int>ans;
        int k = (to_string(x)).size(), j = 0;
        while (j != k)
        {
            int rem = x % 10;
            if (rem != 0)
            {
                ans.push_back( rem * pow(10, j)) ;
            }
            j++;
            x/=10;
        }
        cout<<ans.size()<<endl;
        for(auto it:ans)  cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}