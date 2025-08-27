// Problem Definition: Given an array A[1..n], count the number of inversions, i.e., pairs (i, j) such that
// i < j and A[i] > A[j].
// Example: A = [2, 4, 1, 3, 5] Inversions: (2, 1),(4, 1),(4, 3) Total = 3.

#include<bits/stdc++.h>
using namespace std;

int mergeAndCount(vector<int>& arr, int l, int m, int r) {
    int leftSize = m - l + 1;
    int rightSize = r - m;
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l, inv_count = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inv_count += (leftSize - i);
        }
    }
    while (i < leftSize) arr[k++] = left[i++];
    while (j < rightSize) arr[k++] = right[j++];
    return inv_count;
}

int mergeSortAndCount(vector<int>& arr, int l, int r) {
    int inv_count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        inv_count += mergeSortAndCount(arr, l, m);
        inv_count += mergeSortAndCount(arr, m + 1, r);
        inv_count += mergeAndCount(arr, l, m, r);
    }
    return inv_count;
}

int main() {
    vector<int> A = {2, 4, 1, 3, 5};
    int result = mergeSortAndCount(A, 0, A.size() - 1);
    cout << "Total inversions: " << result << endl;
    return 0;
}