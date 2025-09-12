#include <iostream>
#include <vector>

using namespace std;

void computePrefixMatrix(vector<vector<int>>& mat, vector<vector<int>>& prefix) {
    int rows = mat.size();
    int cols = mat[0].size();

    // Resize prefix matrix to have one extra column
    prefix.assign(rows, vector<int>(cols + 1, 0));

    // Compute prefix sum
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j <= cols; j++) { // Start from 1 to accommodate extra column
            prefix[i][j] = prefix[i][j - 1] + mat[i][j - 1];
        }
    }
}

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = mat.size(), cols = mat[0].size();
    vector<vector<int>> prefix;

    computePrefixMatrix(mat, prefix);

    cout << "Original Matrix:\n";
    printMatrix(mat);

    cout << "\nPrefix Matrix with Extra Column:\n";
    printMatrix(prefix);

    return 0;
}
