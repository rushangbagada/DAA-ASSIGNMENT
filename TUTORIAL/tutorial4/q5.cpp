#include <iostream>
#include <vector>
using namespace std;

int minStops(int tank, int distance, vector<int>& pumps) {
    pumps.push_back(distance); 
    int stops = 0, curr = 0, i = 0, n = pumps.size();
    while (curr + tank < distance) {
        int next = curr;
        while (i < n && pumps[i] <= curr + tank) {
            next = pumps[i];
            i++;
        }
        if (next == curr) return -1; 
        if (next < distance) stops++;
        curr = next;
    }
    return stops;
}

int main() {
    int tank = 10;
    int distance = 25;
    vector<int> pumps = {4, 7, 12, 18, 22};
    int result = minStops(tank, distance, pumps);
    if (result == -1)
        cout << "Cannot reach destination" << endl;
    else
        cout << "Minimum stops: " << result << endl;
    return 0;
}
