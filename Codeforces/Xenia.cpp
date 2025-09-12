#include <bits/stdc++.h>
using namespace std;

const int MAX = (1 << 17);
vector<int> seg(4 * MAX);
vector<int> arr;

void build(int idx, int l, int r, int op) {
    if (l == r) {
        seg[idx] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * idx + 1, l, mid, !op);
    build(2 * idx + 2, mid + 1, r, !op);

    if (op)
        seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
    else
        seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
}

void update(int idx, int l, int r, int pos, int val, int op) {
    if (l == r) {
        seg[idx] = val;
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * idx + 1, l, mid, pos, val, !op);
    else
        update(2 * idx + 2, mid + 1, r, pos, val, !op);

    if (op)
        seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
    else
        seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
}

int main() {
    int n, m;
    cin >> n >> m;
    int size = 1 << n;
    arr.resize(size);

    for (int i = 0; i < size; ++i)
        cin >> arr[i];

    // n&1 == 1 --> OR at root
    build(0, 0, size - 1, n % 2);

    while (m--) {
        int p, b;
        cin >> p >> b;
        --p;  // 0-based indexing
        update(0, 0, size - 1, p, b, n % 2);
        cout << seg[0] << "\n";
    }

    return 0;
}
