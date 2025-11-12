 #include <bits/stdc++.h>
 using namespace std;
 using ll = long long;

 unordered_map<int, set<int>> adj;

 inline  bool valid(int r, int c)
 {
     if (adj.find(r) == adj.end())
         return false;
     return adj[r].count(c);
 }

 int main()
 {
     ios::sync_with_stdio(false);
     cin.tie(nullptr);

     int x0, y0, x1, y1;
     cin >> x0 >> y0 >> x1 >> y1;

     int t;
     cin >> t;

    
     for (int i = 0; i < t; i++)
     {
         int x, y, z;
         cin >> x >> y >> z;
      
         for (int c = y; c <= z; c++)
             adj[x].insert(c);
     }

     if (!valid(x0, y0) || !valid(x1, y1))
     {
         cout << -1 << "\n";
         return 0;
     }

    
     queue<array<int, 3>> q;
     q.push({x0, y0, 0});

   
     unordered_set<long long> vis;
     auto encode = [&](int r, int c)
     {
         return (1LL * r << 32) | (unsigned int)c;
     };
     vis.insert(encode(x0, y0));

     int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
     int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

     while (!q.empty())
     {
         auto [r, c, d] = q.front();
         q.pop();

         if (r == x1 && c == y1)
         {
             cout << d << "\n";
             return 0;
         }

         for (int i = 0; i < 8; i++)
         {
             int nr = r + dr[i];
             int nc = c + dc[i];
             if (valid(nr, nc))
             {
                 long long code = encode(nr, nc);
                 if (!vis.count(code))
                 {
                     vis.insert(code);
                     q.push({nr, nc, d + 1});
                 }
             }
         }
     }

   
     cout << -1 << "\n";
     return 0;
 }
