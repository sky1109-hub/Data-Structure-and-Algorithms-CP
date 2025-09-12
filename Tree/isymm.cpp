#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
    node(int n) : val(n), left(NULL), right(NULL) {}
};

node* build(vector<int> &a) {
    if (a.empty() || a[0] == -1)
        return nullptr;

    node *root = new node(a[0]);
    queue<node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < a.size()) {
        auto cur = q.front();
        q.pop();

        // left child
        if (i < a.size() && a[i] != -1) {
            cur->left = new node(a[i]);
            q.push(cur->left); 
        }
        i++;

        // right child
        if (i < a.size() && a[i] != -1) {
            cur->right = new node(a[i]);
            q.push(cur->right); 
        }
        i++;
    }
    return root;
}

void printd(vector<int> &a) {
    for (auto it : a) {
        if (it != -1) cout << it << " ";
    }
    cout << endl;
}

bool ismirror(node* a, node* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return ismirror(a->left, b->right) &&
           ismirror(a->right, b->left);
}

bool issym(node *root) {
    if (!root) return true;
    return ismirror(root->left, root->right);
}

int main() {
    vector<int> a = {1, 2, 3, 0, 4, 4, -1}; 
    node *root = build(a);

    if (issym(root))
        cout << "Symmetric" << endl;
    else
        cout << "Not Symmetric" << endl;

    printd(a);
    return 0;
}
