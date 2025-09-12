#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate number of parity bits
int calculateParityBits(int m) {
    int r = 0;
    while ((1 << r) < (m + r + 1)) {
        r++;
    }
    return r;
}

// Function to insert parity bits as placeholders ('0') in the correct positions
void insertParityBits(const string& data, vector<char>& code, int m, int r) {
    int j = 0;
    int totalBits = m + r;

    code.resize(totalBits + 1); // 1-based indexing

    for (int i = 1; i <= totalBits; ++i) {
        if ((i & (i - 1)) == 0) {
            code[i] = '0'; // Placeholder for parity bits
        } else {
            code[i] = data[j++];
        }
    }
}

// Function to set actual parity bits using even parity
void setParityBits(vector<char>& code, int totalBits, int r) {
    for (int i = 0; i < r; ++i) {
        int parityPos = 1 << i;
        int count = 0;

        for (int j = 1; j <= totalBits; ++j) {
            if (j & parityPos) {
                if (code[j] == '1') count++;
            }
        }

        code[parityPos] = (count % 2 == 0) ? '0' : '1';
    }
}

int main() {
    string data;
    cout << "Enter the message in bit form: ";
    cin >> data;

    int m = data.length();
    int r = calculateParityBits(m);
    int totalBits = m + r;

    vector<char> code;
    insertParityBits(data, code, m, r);
    setParityBits(code, totalBits, r);

    cout << "Encoded Hamming code: ";
    for (int i = 1; i <= totalBits; ++i) {
        cout << code[i];
    }
    cout << endl;

    return 0;
}
