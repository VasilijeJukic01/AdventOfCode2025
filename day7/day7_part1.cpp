#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

int solve(vector<string>& grid) {
    int m = grid.size(), n = grid[0].size();

    int startRow = -1, startCol = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'S') {
                startRow = i;
                startCol = j;
                break;
            }
        }
        if (startRow != -1) break;
    }

    stack<pair<int, int>> s;
    s.push({startRow, startCol});

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int splits = 0;

    while (!s.empty()) {
        pair<int, int> curr = s.top();
        s.pop();

        int r = curr.first, c = curr.second;

        while (r < m) {
            if (c < 0 || c >= n) break;

            char cell = grid[r][c];
            if (cell == '^') {
                if (!visited[r][c]) {
                    visited[r][c] = true;
                    splits++;
                    s.push({r, c - 1});
                    s.push({r, c + 1});
                }
                break;
            }
            r++;
        }
    }

    return splits;
}

int main() {
    vector<string> grid;

    string line;

    while (getline(cin, line)) {
        if (line == "stop") break;
        grid.push_back(line);
    }

    cout << solve(grid);

    return 0;
}