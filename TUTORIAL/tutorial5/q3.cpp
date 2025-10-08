#include <iostream>
#include <vector>
using namespace std;

int minCut(string s) {
    int n = s.length();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    vector<int> cuts(n, 0);

    for (int i = 0; i < n; ++i) {
        int min_cuts = i;
        for (int j = 0; j <= i; ++j) {
            if (s[j] == s[i] && (i-j < 2 || isPal[j+1][i-1])) {
                isPal[j][i] = true;
                min_cuts = (j == 0) ? 0 : min(min_cuts, cuts[j-1] + 1);
            }
        }
        cuts[i] = min_cuts;
    }
    return cuts[n-1];
}

int main() {
    string S = "aab";
    cout << "Minimum cuts = " << minCut(S) << endl;
    return 0;
}