// Problem Definition: Given an array A of n elements
//  A=[A[0],A[1],...,A[n − 1]],
//  f
//  ind an index i (0 ≤ i < n) such that
//  A[i] ≥ A[i −1] and A[i] ≥ A[i+1],
//  where
//  • for the first element (i = 0), we only require A[0] ≥ A[1],
//  • for the last element (i = n−1), we only require A[n−1] ≥ A[n−2].
//  Such an element A[i] is called a peak element, and the index i is called a peak index.
//  Your task is to find and return any one peak index that satisfies the above condition.
//  Example: A = [1,3,20,4,1,0] Peak = index 2 (value 20).

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(const vector<int>& A) {
    int n = A.size();
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        bool leftOK = (mid == 0) || (A[mid] >= A[mid - 1]);
        bool rightOK = (mid == n - 1) || (A[mid] >= A[mid + 1]);
        if (leftOK && rightOK)
            return mid; 
        else if (mid > 0 && A[mid - 1] > A[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main() {
    vector<int> A = {1, 3, 20, 4, 1, 0};
    int peakIdx = findPeakElement(A);
    cout << "Peak index: " << peakIdx << " (value " << A[peakIdx] << ")" << endl;
    return 0;
}


