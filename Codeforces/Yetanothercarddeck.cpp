#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    deque<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (q--)
    {
        int x;
        cin >> x;
        auto it = find(a.begin(), a.end(), x);
        int idx = it - a.begin();
        a.erase(it);
        a.push_front(x);

        cout << idx+1 << " ";
    }
    cout << endl;
    return 0;
}