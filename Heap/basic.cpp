#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    int n, size = 0;
    vector<int> a;

    Heap(int _n) : n(_n) {
        a.resize(n + 1); // 1-based indexing
    }

    void insert(int val) {
        size++;
        a[size] = val;
        int i = size;
        while (i > 1) { // root is at index 1
            int par = i / 2;
            if (a[par] < a[i]) {
                swap(a[par], a[i]);
                i = par;
            } else break;
        }
    }

   void del() {
    a[1] = a[size];
    size--;
    int i = 1;
    while (true) {
        int left = 2 * i, right = 2 * i + 1, largest = i;

        if (left <= size && a[left] > a[largest]) largest = left;
        if (right <= size && a[right] > a[largest]) largest = right;

        if (largest != i) {
            swap(a[i], a[largest]);
            i = largest;
        } else break;
    }
}
   void max_element(){
    cout<<"Max Element: "<<a[1]<<endl;
   }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h(5);
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.print();
    h.del();
    h.print();
    h.insert(6);
    
     
    h.print();
     h.del();
     h.print();
    return 0;
}
