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

bool binarySearch(const vector<pair<long long, long long>>& ranges, long long id) {
    long long start = 0;
    long long end = ranges.size() - 1;

    while (start <= end) {
        long long mid = start + (end - start) / 2;
        if (id >= ranges[mid].first && id <= ranges[mid].second) return true;
        if (id < ranges[mid].first) end = mid - 1;
        else start = mid + 1;
    }

    return false;
}

long long solve(vector<pair<long long, long long>>& raw, vector<long long>& ids) {
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
    for (int i = 0; i < ids.size(); i++) {
        if (binarySearch(merged, ids[i])) total++;
    }

    return total;
}

int main() {
    vector<pair<long long, long long>> ranges;
    vector<long long> ids;

    string line;
    bool flag = true;

    while (getline(cin, line)) {
        if (line == "stop") break;
        if (line.empty()) {
            flag = false;
            continue;
        }
        if (flag) ranges.push_back(parseString(line));
        else ids.push_back(stoll(line));
    }

    cout << solve(ranges, ids);

    return 0;
}