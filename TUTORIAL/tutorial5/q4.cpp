#include <iostream>
#include <vector>
using namespace std;

int eggDrop(int k, int n) {
    vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1) dp[i][j] = j;
            else {
                dp[i][j] = j;
                for (int x = 1; x <= j; ++x) {
                    int res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                    if (res < dp[i][j]) dp[i][j] = res;
                }
            }
        }
    }
    return dp[k][n];
}

int main() {
    int k = 2, n = 10;
    cout << "Minimum number of attempts = " << eggDrop(k, n) << endl;
    return 0;
}