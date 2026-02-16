#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> p;
    for (int i = 2; i <= limit; i++)
        if (isPrime[i]) p.push_back(i);
   

   for(int i=0;i<p.size();i+=100){
     cout<<p[i]<<endl;
   }     
    
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

       simpleSieve(1e8-1);
      
      
       return 0;
        
    }

