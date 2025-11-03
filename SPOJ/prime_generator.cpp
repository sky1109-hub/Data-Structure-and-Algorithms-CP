#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; i++)
        if (isPrime[i]) primes.push_back(i);

    return primes;
}


void segmentedSieve(ll l, ll r) {
    vector<int> primes = simpleSieve(sqrt(r) + 1);
    vector<bool> isPrime(r - l + 1, true);

    for (int p : primes) {
        ll start = max((ll)p * p, ((l + p - 1) / p) * (ll)p);
        for (ll j = start; j <= r; j += p)
            isPrime[j - l] = false;
    }

    if (l == 1) isPrime[0] = false;

    for (ll i = 0; i <= r - l; i++) {
        if (isPrime[i])
            cout << (l + i) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        segmentedSieve(l, r);
        cout << "\n";
    }
}
