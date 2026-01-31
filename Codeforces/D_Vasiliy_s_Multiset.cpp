#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    Node* link[2];
    int c, p;
    Node() {
        link[0] = link[1] = NULL;
        c = 0;
        p = 0;
    }
};

class trie {
private:
    Node *root;

public:
    trie() {
        root = new Node();
    }

  
    void insert(const string &s) {
        Node *cur = root;
        cur->p++;  

        for (char ch : s) {
            int bit = ch - '0';
            if (cur->link[bit] == NULL)
                cur->link[bit] = new Node();
            cur = cur->link[bit];
            cur->p++;
        }
        cur->c++; 
    }

    
    void del(const string &s) {
        Node *cur = root;

        cur->p--;  

        for (char ch : s) {
            int bit = ch - '0';
            cur = cur->link[bit];
            cur->p--;
        }
        cur->c--;
    }

    
    ll findmax(const string &s) {
        Node *cur = root;
        ll ans = 0;

        for (char ch : s) {
            int bit = ch - '0';
            int want = bit ^ 1;

            if (cur->link[want] != NULL && cur->link[want]->p > 0) {
                ans = (ans << 1) | 1;
                cur = cur->link[want];
            } else {
                ans = (ans << 1);
                cur = cur->link[bit];
            }
        }
        return ans;
    }
};

string toBinary(int n) {
    string s = "";
    for (int i = 31; i >= 0; i--) {
        s += (n & (1LL << i)) ? '1' : '0';
    }
    return s;
}

int main() {
    int te;
    cin >> te;

    trie t;
   

    while (te--) {
        char ch;
        int n;
        cin >> ch >> n;

        string s = toBinary(n);

        if (ch == '+')
            t.insert(s);
        else if (ch == '-')
            t.del(s);
        else
            cout << t.findmax(s) << endl;
    }
    return 0;
}
