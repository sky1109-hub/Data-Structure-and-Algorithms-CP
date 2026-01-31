// #include <bits/stdc++.h>
// using namespace std;

// unordered_map<int, int> dp; // memo table

// int solve(int n, int m)
// {
//     queue<tuple<int, int, int>> q;
//     q.push({n, m, 0});
//     while (!q.empty())
//     {
//         int x = q.size();
//         for (int i = 0; i < x; i++)
//         {
//             auto [n1, m1, c] = q.front();
//             q.pop(); if(n1<0)  return INT_MAX;
//             if (n1 == m1)
//                 return c;
//               if(n1>0){  
//              q.push({2*n1,m,c+1}); 
//             q.push({n1-1,m,c+1});  } 
//         }
//     }
//     return 0;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     cout << solve(n, m) << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m)
{
    queue<pair<int,int>> q;
    unordered_set<int> visited;

    q.push({n, 0});
    visited.insert(n);

    while (!q.empty())
    {
        auto [x, steps] = q.front();
        q.pop();

        if (x == m) return steps;

        // move x*2
        if (x < 2*m && !visited.count(x*2)) {
            visited.insert(x*2);
            q.push({x*2, steps + 1});
        }

     
        if (x > 0 && !visited.count(x-1)) {
            visited.insert(x-1);
            q.push({x-1, steps + 1});
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
}
