#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
	int value, weight;
	double ratio;
};

bool cmp(Item a, Item b) {
	return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, vector<Item>& items) {
	sort(items.begin(), items.end(), cmp);
	double totalValue = 0.0;
	int currWeight = 0;
	for (auto& item : items) {
		if (currWeight + item.weight <= W) {
			currWeight += item.weight;
			totalValue += item.value;
		} else {
			int remain = W - currWeight;
			totalValue += item.ratio * remain;
			break;
		}
	}
	return totalValue;
}

int main() {
	int n = 3;
	int W = 50;
	vector<Item> items = {
		{60, 10, 60.0/10},
		{100, 20, 100.0/20},
		{120, 30, 120.0/30}
	};
	double maxProfit = fractionalKnapsack(W, items);
	cout << "Maximum profit: " << maxProfit << endl;
	return 0;
}
