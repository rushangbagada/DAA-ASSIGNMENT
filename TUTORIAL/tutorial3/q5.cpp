
// Problem Definition: Sort an array using Dual Pivot QuickSort. First, choose two pivots p and q such
// that p < q. The array is then partitioned into three segments: elements less than p, elements between p and
// q, and elements greater than q. Finally, each segment is recursively sorted to obtain the fully sorted array.
// Example: A = [4,7,2,9,1,5] Pivots = (2,7) Partitions: [1]|[4,5]|[9] Sorted = [1,2,4,5,7,9].
#include <bits/stdc++.h>
using namespace std;


void dualPivotQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        
        if (arr[low] > arr[high])
            swap(arr[low], arr[high]);
        int p = arr[low], q = arr[high];
        int lt = low + 1, gt = high - 1, i = lt;
        while (i <= gt) {
            if (arr[i] < p) {
                swap(arr[i], arr[lt]);
                lt++;
            } else if (arr[i] > q) {
                swap(arr[i], arr[gt]);
                gt--;
                i--; 
            }
            i++;
        }
        lt--; gt++;
        swap(arr[low], arr[lt]);
        swap(arr[high], arr[gt]);
        
        dualPivotQuickSort(arr, low, lt - 1);
        dualPivotQuickSort(arr, lt + 1, gt - 1);
        dualPivotQuickSort(arr, gt + 1, high);
    }
}

int main() {
    vector<int> arr = {4, 7, 2, 9, 1, 5};
    dualPivotQuickSort(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}


