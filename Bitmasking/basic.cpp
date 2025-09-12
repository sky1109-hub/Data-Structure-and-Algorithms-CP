#include <bits/stdc++.h>
using namespace std;

class Subset {
public:
    int n, k;
    Subset(int n): n(n), k(0) {}

    void add(int x) {
       
        k |= (1 << (x-1));
    }

    void remove(int x) {
      
        k &= ~(1 << (x-1));
    }

    void toggle(int x) {
      
        k ^= (1 << (x-1));
    }

    void display(int x) {
        cout << "{ ";
        for (int bit = 0; bit < n; bit++) {
            if (x & (1 << bit)) {
                cout << bit+1 << " ";
            }
        }
        cout << "}" << endl;
    }
};

int main() {
     
    Subset s(5);
    s.add(2);
    s.add(4);
    s.display(12);   // { 2 4 }
    // s.remove(2);
    // s.display();   // { 4 }
    // s.toggle(1);
    // s.display();   // { 1 4 }
     s.display(31);
    return 0;
}
