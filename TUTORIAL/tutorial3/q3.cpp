// Problem Definition: Given an unsorted array A[1..n] and an integer k, find the k-th smallest element.
// Example: A = [7, 10, 4, 3, 20, 15], k = 3 Sorted = [3, 4, 7, 10, 15, 20] Answer = 7.

#include<bits/stdc++.h>
using namespace std;

int findKthSmallest(vector<int>& A, int k) {
    priority_queue<int> maxHeap;
    for (int i = 0; i < A.size(); i++) {
        maxHeap.push(A[i]);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main() {
    vector<int> A = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int result = findKthSmallest(A, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;
    return 0;
}
