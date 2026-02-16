#include <iostream>
#include <vector>

using namespace std;

void printSubsequences(vector<int>& arr, vector<int>& temp, int index) {
    if (index == arr.size()) {
        // Base case: Print the current subsequence
        cout << "{ ";
        for (int num : temp) cout << num << " ";
        cout << "}" << endl;
        return;
    }

    // Include the current element
    temp.push_back(arr[index]);
    printSubsequences(arr, temp, index + 1);

    // Exclude the current element
    temp.pop_back();
    printSubsequences(arr, temp, index + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> temp;
    
    printSubsequences(arr, temp, 0);

    return 0;
}
