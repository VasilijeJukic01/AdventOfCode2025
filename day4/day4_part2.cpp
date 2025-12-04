#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

bool isSafe(int m, int n, int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= n) return false;
    return true;
}

int countNeighbors(vector<string>& grid, int i, int j, int m, int n, int* dI, int* dJ) {
    int count = 0;
    
    for (int k = 0; k < 8; k++) {
        int I = i + dI[k];
        int J = j + dJ[k];
        if (isSafe(m, n, I, J) && grid[I][J] == '@') {
            count++;
        }
    }
    
    return count;
}

long long solve(vector<string>& grid) {
    int m = grid.size(), n = grid[0].size();
    long long total = 0;
    
    int dI[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dJ[] = {0, -1, -1, -1, 0, 1, 1, 1};
    
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '@') {
                if (countNeighbors(grid, i, j, m, n, dI, dJ) < 4) {
                    q.push({i, j});
                }
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        
        int i = p.first, j = p.second;
        
        if (grid[i][j] != '@') continue;
        
        grid[i][j] = '.';
        total++;
        
        for (int k = 0; k < 8; k++) {
            int I = i + dI[k];
            int J = j + dJ[k];
            if (isSafe(m, n, I, J) && grid[I][J] == '@') {
                if (countNeighbors(grid, I, J, m, n, dI, dJ) < 4) {
                    q.push({I, J});
                }
            }
        }
    }
    
    return total;
}

int main() 
{
    vector<string> grid;
    string x;
    
    while (cin >> x) {
        if (x == "0") break;
        grid.push_back(x);
    }
    
    long long result = solve(grid);
    
    cout << result;
    
    return 0;
}