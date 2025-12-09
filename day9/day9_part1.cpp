#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctgmath>
#include <vector>

using namespace std;

long long solve(vector<pair<long long, long long>>& tiles) {
    long long maxArea = 0;

    for (int i = 0; i < tiles.size(); i++) {
        for (int j = i + 1; j < tiles.size(); j++) {
            long long w = abs(tiles[i].first - tiles[j].first) + 1;
            long long h = abs(tiles[i].second - tiles[j].second) + 1;
            long long area = w * h;

            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}

int main() {
    vector<pair<long long, long long>> tiles;
    string line;

    while (getline(cin, line)) {
        if (line == "stop") break;

        stringstream ss(line);
        long long x = -1, y = -1;
        string token;
        while (getline(ss, token, ',')) {
            if (x == -1) x = stoi(token);
            else y = stoi(token);
        }
        tiles.push_back({x, y});
    }

    cout << solve(tiles);

    return 0;
}