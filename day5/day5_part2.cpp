#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

pair<long long, long long> parseString(const string& s) {
    long long start, end;
    char dash;
    stringstream ss(s);
    ss >> start >> dash >> end;
    return {start, end};
}

long long solve(vector<pair<long long, long long>>& raw) {
    sort(raw.begin(), raw.end());

    vector<pair<long long, long long>> merged;
    merged.push_back(raw[0]);

    for (int i = 1; i < raw.size(); i++) {
        // Overlap -> [1, 5] [2, 7]
        if (raw[i].first <= merged.back().second) {
            merged.back().second = max(merged.back().second, raw[i].second);
        }
        // No Overlap
        else merged.push_back(raw[i]);
    }

    long long total = 0;

    for (int i = 0; i < merged.size(); i++) {
        total += merged[i].second - merged[i].first + 1;
    }

    return total;
}

int main() {
    vector<pair<long long, long long>> ranges;

    string line;

    while (getline(cin, line)) {
        if (line == "stop") break;
        ranges.push_back(parseString(line));
    }

    cout << solve(ranges);

    return 0;
}