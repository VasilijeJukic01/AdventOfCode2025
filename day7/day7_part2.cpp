#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

long long countPaths(vector<string>& grid, vector<vector<long long>>& memo, int row, int col) {
    int m = grid.size();
    int n = grid[0].size();

    while (row < m) {
        if (col < 0 || col >= n) return 0;

        char cell = grid[row][col];
        if (cell == '^') {
            if (memo[row][col] != -1) return memo[row][col];

            long long leftPaths = countPaths(grid, memo, row, col - 1);
            long long rightPaths = countPaths(grid, memo, row, col + 1);

            return memo[row][col] = leftPaths + rightPaths;
        }
        row++;
    }
    // Bottom
    return 1;
}


long long solve(vector<string>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<long long>> memo(m, vector<long long>(n, -1));

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

    return countPaths(grid, memo, startRow, startCol);
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