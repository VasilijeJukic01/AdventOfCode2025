#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> adj;
unordered_map<string, long long> memo;

long long solve(string current) {
    if (current == "out") return 1;
    if (memo.count(current)) return memo[current];

    long long total = 0;
    if (adj.count(current)) {
        vector<string>& neighbors = adj[current];
        for (int i = 0; i < neighbors.size(); i++) {
            total += solve(neighbors[i]);
        }
    }

    return memo[current] = total;
}

int main() {
    string line;

    while (getline(cin, line)) {
        if (line == "stop") break;

        int delim = line.find(':');
        string src = line.substr(0, delim);
        stringstream ss(line.substr(delim + 1));
        string dest;
        while (ss >> dest) {
            adj[src].push_back(dest);
        }
    }

    cout << solve("you");

    return 0;
}