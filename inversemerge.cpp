#include <iostream>
using namespace std;

// Merge function to count inversions
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long invCount = 0;

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i); 
        }
    }

    while (i <= mid - 1) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];

    return invCount;
}

// Merge sort function to count inversions
long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        invCount += mergeSortAndCount(arr, temp, left, mid);//left subarray
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);//right sub aaray
        invCount += mergeAndCount(arr, temp, left, mid + 1, right);//crosss inversion
    }
    return invCount;
}

// Wrapper function
long long countInversions(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

// Main function
int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Number of inversions: " << countInversions(arr, n) << endl;
    return 0;
}
