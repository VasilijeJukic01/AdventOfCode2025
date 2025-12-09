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

long long solve(vector<vector<long long>>& boxes) {
    int n = boxes.size();

    // {distance, {indexU, indexV}}
    vector<pair<long long, pair<int, int>>> edges;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long x = boxes[i][0] - boxes[j][0];
            long long y = boxes[i][1] - boxes[j][1];
            long long z = boxes[i][2] - boxes[j][2];
            long long d = x * x + y * y + z * z;

            edges.push_back({d, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Starting with n components
    int groups = n;

    // Kruskal
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        int rootU = findRoot(u, parent);
        int rootV = findRoot(v, parent);

        if (rootU != rootV) {
            parent[rootV] = rootU;
            groups--;
            if (groups == 1) return boxes[u][0] * boxes[v][0];
        }
    }

    return 0;
}

int main() {
    vector<vector<long long>> boxes;
    string line;

    while (getline(cin, line)) {
        if (line == "stop") break;

        stringstream ss(line);
        vector<long long> curr;
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