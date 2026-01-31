#include <bits/stdc++.h>
using namespace std;

string s;

class node {
public:
    int open, close, full;

    node() : open(0), close(0), full(0) {}  

    node(int x, int y, int z) : open(x), close(y), full(z) {} 
};
void build(int idx,int l,int h,vector<node>&seg){
    if(l==h){
        if(s[l]=='(') seg[idx].open=1;
        else if(s[l]==')') seg[idx].close=1;
        seg[idx].full=0;
        return;
    } int m=(l+h)/2;
     build(2*idx+1,l,m,seg);
     build(2*idx+2,m+1,h,seg);

   seg[idx].open=seg[2*idx+1].open+seg[2*idx+2].open-min(seg[2*idx+1].open,seg[2*idx+2].close);
   seg[idx].close=seg[2*idx+1].close+seg[2*idx+2].close-min(seg[2*idx+1].open,seg[2*idx+2].close);
   seg[idx].full=  seg[2*idx+1].full+seg[2*idx+2].full+min(seg[2*idx+1].open,seg[2*idx+2].close);
}
node merge(const node &a, const node &b) {
    int matched = min(a.open, b.close);
    return node(
        a.open + b.open - matched,
        a.close + b.close - matched,
        a.full + b.full + matched
    );
}

node query(int idx, int ql, int qr, int low, int high, vector<node>& seg) {
    
    if (qr < low || ql > high) return node(0, 0, 0);

    
    if (ql <= low && high <= qr) return seg[idx];

    
    int mid = (low + high) / 2;
    node left = query(2 * idx + 1, ql, qr, low, mid, seg);
    node right = query(2 * idx + 2, ql, qr, mid + 1, high, seg);
    return merge(left, right);
}


int main() {
    getline(cin, s);  
   int n=s.size();
    int q;
    cin >> q;

    vector<node> seg(4*n);
    build(0,0,n-1,seg);
    while(q--){
     int l, r;
    cin >> l >> r;
    l--, r--; 
    int res = query(0, l, r, 0, n - 1, seg).full;
    cout << 2 * res << "\n";
    }
    

    return 0;
}
