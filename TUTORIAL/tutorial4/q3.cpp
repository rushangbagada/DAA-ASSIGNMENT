#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Custom comparator for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to print Huffman codes
void printCodes(Node* root, string code, int &totalCost) {
    if (!root) return;

    // Leaf node
    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << endl;
        totalCost += root->freq * code.length();
        return;
    }

    printCodes(root->left, code + "0", totalCost);
    printCodes(root->right, code + "1", totalCost);
}

int main() {
    // Character frequencies
    map<char, int> freq = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}
    };

    // Priority queue (min-heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes
    for (auto &p : freq) {
        pq.push(new Node(p.first, p.second));
    }

    // Build Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    // Print codes and compute cost
    int totalCost = 0;
    cout << "Huffman Codes:\n";
    printCodes(root, "", totalCost);

    cout << "\nTotal Huffman Cost: " << totalCost << endl;

    return 0;
}
