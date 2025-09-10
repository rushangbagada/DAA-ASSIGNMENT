// Given an array a
// , let f(x)
//  be the number of occurrences of x
//  in the array a
// . For example, when a=[1,2,3,1,4]
// , then f(1)=2
//  and f(3)=1
// .

// You have an array b
//  of size n
// . Please determine if there is an array a
//  of size n
//  such that f(ai)=bi
//  for all 1≤i≤n
// . If there is one, construct it.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤104
// ). The description of the test cases follows.

// The first line of each test case contains an integer n
//  (1≤n≤2⋅105
// ).

// The second line contains n
//  integers b1,b2,…,bn
//  (1≤bi≤n
// ).

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output −1
//  if there is no valid array a
// .

// Otherwise, print the array a
//  of n
//  integers on a new line. The elements should satisfy 1≤ai≤n
// .

// Example
// InputCopy
// 3
// 4
// 1 2 3 4
// 6
// 1 2 2 3 3 3
// 6
// 6 6 6 6 6 6
// OutputCopy
// -1
// 4 5 5 6 6 6
// 2 2 2 2 2 2
// Note
// In the first test case, it can be shown that no array matches the requirement.

// In the second test case, 4
// , 5
// , 6
//  appear 1,2,3
//  times respectively. Thus, the output array is correct as f(4),f(5),f(5),f(6),f(6),f(6)
//  are 1,2,2,3,3,3
//  respectively.


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        map<int, vector<int>> fr;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            fr[b[i]].push_back(i);
        }

        bool valid = true;
        for (auto &e : fr) {
            int freq = e.first;
            vector<int> &j = e.second;
            if (j.size() % freq != 0) {
                cout << -1 << "\n";
                valid = false;
                break;
            }
        }
        if (!valid) continue;

        vector<int> a(n);
        int v = n;
        for (auto &e : fr) {
            int freq = e.first;
            vector<int> &i = e.second;
            for (size_t j = 0; j < i.size(); j += freq) {
                for (size_t k = 0; k < freq; ++k) {
                    a[i[j + k]] = v;
                }
                v--;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i + 1 == n ? "\n" : " ");
        }
    }
    return 0;
}