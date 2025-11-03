#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> p;
void simpleSieve(ll limit)
{
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= limit; i++)
        if (isPrime[i])
            p.push_back(i);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    simpleSieve(1e9 );
    int t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        cout << p[x-1] << endl;
    }

    return 0;
}
