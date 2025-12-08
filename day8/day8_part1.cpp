#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctgmath>
#include <vector>

using namespace std;

// Finds the root of the set containing element i
int findRoot(int i, vector<int>& parent) {
    if (parent[i] == i) return i;
    return parent[i] = findRoot(parent[i], parent);
}

double distance(vector<int>& a, vector<int>& b) {
    long long x = a[0] - b[0];
    long long y = a[1] - b[1];
    long long z = a[2] - b[2];

    return sqrt(x * x + y * y + z * z);
}

int solve(vector<vector<int>>& boxes) {
    int n = boxes.size();

    // {distance, {indexU, indexV}}
    vector<pair<double, pair<int, int>>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = distance(boxes[i], boxes[j]);
            edges.push_back({d, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());
    
    vector<int> parent(n);
    vector<int> groupSize(n, 1);

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int connections = 1000;
    if (edges.size() < connections) connections = edges.size();

    for (int i = 0; i < connections; i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        int rootU = findRoot(u, parent);
        int rootV = findRoot(v, parent);

        // If in different sets -> merge
        if (rootU != rootV) {
            parent[rootV] = rootU;
            groupSize[rootU] += groupSize[rootV];
        }
    }

    vector<int> finalSizes;
    for (int i = 0; i < n; ++i) {
        if (parent[i] == i) finalSizes.push_back(groupSize[i]);
    }

    sort(finalSizes.rbegin(), finalSizes.rend());

    int result = 1;
    for (int i = 0; i < 3 && i < finalSizes.size(); i++) {
        result *= finalSizes[i];
    }

    return result;
}

int main() {
    vector<vector<int>> boxes;
    string line;

    while (getline(cin, line)) {
        if (line == "stop") break;

        stringstream ss(line);
        vector<int> curr;
        string token;
        while (getline(ss, token, ',')) {
            curr.push_back(stoi(token));
        }
        boxes.push_back(curr);
    }

    // Plzz work :(
    cout << solve(boxes);

    return 0;
}