#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

long long createBtnMask(string content) {
    long long mask = 0;
    stringstream ss(content);
    string token;

    while (getline(ss, token, ',')) {
        int index = stoi(token);
        mask = mask | (1LL << index);
    }

    return mask;
}

int solve(string line) {
    long long targetMask = 0;
    vector<long long> buttons;

    int open = line.find('[');
    int closed = line.find(']');

    if (open != string::npos && closed != string::npos) {
        string pattern = line.substr(open + 1, closed - open - 1);
        for (int i = 0; i < pattern.length(); i++) {
            if (pattern[i] == '#') {
                targetMask = targetMask | (1LL << i);
            }
        }
    }

    int pos = closed + 1;
    while (true) {
        open = line.find('(', pos);
        if (open == string::npos) break;

        int closed = line.find(')', open);
        string content = line.substr(open + 1, closed - open - 1);
        buttons.push_back(createBtnMask(content));
        pos = closed + 1;
    }

    int n = buttons.size();

    for (int k = 0; k <= n; k++) {
        vector<int> selector(n, 0);
        for (int i = n - k; i < n; i++) {
            selector[i] = 1;
        }

        // Check all combinations
        do {
            long long state = 0;
            for (int i = 0; i < n; i++) {
                if (selector[i]) state ^= buttons[i];
            }
            if (state == targetMask) return k;
        } while (next_permutation(selector.begin(), selector.end()));
    }

    return 0;
}

int main() {
    string line;
    long long total = 0;

    while (getline(cin, line)) {
        if (line == "stop") break;
        int result = solve(line);
        total += result;
    }

    cout << total;

    return 0;
}