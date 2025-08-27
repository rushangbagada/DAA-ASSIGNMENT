

#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
 long long n;
cin >> n;
vector<long long> result;
        for (long long m = 10; m <= n; m *= 10) {
            long long d = 1 + m;
            if (n % d == 0) {
                long long x = n / d;
                if (x > 0) result.push_back(x);
            }
        }
        sort(result.begin(), result.end());
        if (result.empty()) cout << 0 << "\n";
        else {
            cout << result.size() << "\n";
            for (auto v : result) cout << v << " ";
            cout << "\n";
        }
    }
    return 0;
}       