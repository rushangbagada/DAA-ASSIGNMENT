#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) {
            return {};
        }

        vector<pair<int, int>> events;
        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }
        sort(events.begin(), events.end());
        multiset<int> max_heap;
        max_heap.insert(0);
        vector<vector<int>> skyline;
        int prev_max_height = 0;
        for (const auto& event : events) {
            int x = event.first;
            int h = event.second;
            if (h < 0) {
                max_heap.insert(-h);
            } else {
                max_heap.erase(max_heap.find(h));
            }
            int current_max_height = *max_heap.rbegin();
            if (current_max_height != prev_max_height) {
                skyline.push_back({x, current_max_height});
                prev_max_height = current_max_height;
            }
        }
        return skyline;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> buildings = {{1, 5, 11}, {2, 7, 6}, {3, 9, 13}, {12, 16, 7}, {14, 25, 3}, {19, 22, 18}, {23, 29, 13}, {24, 28, 4}};
    vector<vector<int>> result = sol.getSkyline(buildings);
    
    
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}