#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> adj;
/*
- memo[0] found neither
- memo[1] found dac
- memo[2] found fft
- memo[3] found both
*/
unordered_map<string, long long> memo[4];

long long solve(string current, int state) {
    if (current == "dac") state = state | 1;
    if (current == "fft") state = state | 2;

    if (current == "out") return state == 3 ? 1 : 0;

    if (memo[state].count(current)) return memo[state][current];

    long long total = 0;
    if (adj.count(current)) {
        vector<string>& neighbors = adj[current];
        for (int i = 0; i < neighbors.size(); i++) {
            total += solve(neighbors[i], state);
        }
    }

    return memo[state][current] = total;
}

int main() {
    string line;

    while (getline(cin, line)) {
        if (line == "stop") break;

        int delim = line.find(':');
        if (delim != string::npos) {
            string src = line.substr(0, delim);
            stringstream ss(line.substr(delim + 1));
            string dest;
            while (ss >> dest) {
                adj[src].push_back(dest);
            }
        }
    }

    cout << solve("svr", 0);

    return 0;
}