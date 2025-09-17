#include <bits/stdc++.h>
using namespace std;

struct License {
    double rate;
    int index;
};

int main() {
    vector<double> rates = {2, 3, 1.5};
    double base = 1000;

    // Pair each rate with its original index
    vector<License> licenses;
    for (int i = 0; i < (int)rates.size(); i++) {
        licenses.push_back({rates[i], i});
    }

    // Sort in descending order of rate
    sort(licenses.begin(), licenses.end(),
         [](const License &a, const License &b) {
             return a.rate > b.rate;
         });

    double totalCost = 0;
    int month = 0;

    cout << "Optimal purchase order (0-based indices): ";
    for (auto &lic : licenses) {
        cout << lic.index << " ";
        totalCost += base * pow(lic.rate, month);
        month++;
    }

    cout << "\nMinimum Total Cost: Rs. " << totalCost << endl;
    return 0;
}
