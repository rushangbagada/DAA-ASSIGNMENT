#include <iostream>
#include <vector>
#include <limits>
using namespace std;

double optimalBST(const vector<double>& p) {
    int n = p.size();
    vector<vector<double>> cost(n, vector<double>(n, 0));
    vector<vector<double>> sum(n, vector<double>(n, 0));

    for (int i = 0; i < n; ++i)
        sum[i][i] = p[i];

    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            sum[i][j] = sum[i][j-1] + p[j];
        }
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            cost[i][j] = numeric_limits<double>::max();
            for (int r = i; r <= j; ++r) {
                double left = (r > i) ? cost[i][r-1] : 0;
                double right = (r < j) ? cost[r+1][j] : 0;
                double c = left + right + sum[i][j];
                if (c < cost[i][j]) cost[i][j] = c;
            }
        }
    }
    return cost[0][n-1];
}

int main() {
    vector<double> p = {0.2, 0.5, 0.3};
    cout << "Minimum expected search cost = " << optimalBST(p) << endl;
    return 0;
}