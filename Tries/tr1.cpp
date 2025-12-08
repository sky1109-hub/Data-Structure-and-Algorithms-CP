#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* link[26];
    bool end;

    Node() {
        for(int i = 0; i < 26; i++)
            link[i] = NULL;
        end = false;
    }
};

class trie {
private:
    Node* root;

public:
    trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(node->link[idx] == NULL) {
                node->link[idx] = new Node();
            }
            node = node->link[idx];      // ALWAYS MOVE
        }
        node->end = true;                 // MARK END OF WORD
    }

    bool search(string word) {
        Node* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(node->link[idx] == NULL)
                return false;
            node = node->link[idx];
        }
        return node->end;                 // ensure full word exists
    }

    bool startsWith(string pre) {         // OPTIONAL
        Node* node = root;
        for(char c : pre) {
            int idx = c - 'a';
            if(node->link[idx] == NULL)
                return false;
            node = node->link[idx];
        }
        return true;
    }
};

int main() {
    trie t;
    t.insert("cat");
    t.insert("cap");
    t.insert("car");
    t.insert("dog");

    cout << t.search("cat") << "\n";     // 1
    cout << t.search("cow") << "\n";     // 0
    cout << t.startsWith("ca") << "\n";  // 1

    return 0;
}
