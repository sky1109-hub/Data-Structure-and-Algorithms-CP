#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a=0;
    cin >> n;
    
    while (n--)
    {
        string s;
        cin>>s;
        if (s == "++X")
        {
            ++a;
        }
        else if (s == "--X")
        {
            --a;
        }
        else if (s == "X++")
        {
            a++;
        }
        else
        {
            a--;
        } 
    }
    cout << a << endl;

    return 0;
}