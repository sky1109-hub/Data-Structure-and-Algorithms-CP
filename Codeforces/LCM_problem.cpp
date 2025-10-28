 #include <bits/stdc++.h>
 using namespace std;
  using ll=long long;
 int main() {
     ios::sync_with_stdio(false);
     cin.tie(nullptr);

     int t;
     cin >> t;
     while (t--) {
         ll l, r;
         cin >> l >> r;

         bool found = false;
         for (int i = l; i <= r && !found; i++) {
             for (int j = i + 1; j <= r; j++) {
                 if (1LL*lcm(i, j) >= l && 1LL*lcm(i, j) <= r) {
                     cout << i << " " << j << "\n";
                     found = true;
                     break;
                 }
             }
         }

         if (!found)
             cout << -1 << " " << -1 << "\n";
     }

     return 0;
 }
// #include <iostream>
// using namespace std;

// int main() {
//     cout << __cplusplus << endl;
//     return 0;
// }


