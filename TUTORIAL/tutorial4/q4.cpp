#include <bits/stdc++.h>
using namespace std;

vector<int> placeTowers(vector<int>& houses, int radius) {
    sort(houses.begin(), houses.end());
    vector<int> towers;

    int i = 0, n = houses.size();
    while (i < n) {
        // Step 1: leftmost uncovered house
        int start = houses[i];

        // Step 2: move as far right as we can within 'radius' from start
        while (i < n && houses[i] <= start + radius) i++;

        // Step 3: place tower at the farthest house within range
        int towerPos = houses[i-1];
        towers.push_back(towerPos);

        // Step 4: skip all houses covered by this tower
        while (i < n && houses[i] <= towerPos + radius) i++;
    }
    return towers;
}

int main() {
    vector<int> houses = {1, 2, 6, 9, 11};
    int radius = 4;

    vector<int> towers = placeTowers(houses, radius);

    cout << "Towers placed at: ";
    for (int t : towers) cout << t << " ";
    cout << endl;

    return 0;
}
