#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool isSafe(int m, int n, int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= n) return false;
    return true;
}

long long solve(vector<string>& grid) {
    int m = grid.size(), n = grid[0].size();
    long long total = 0;
    
    int dI[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dJ[] = {0, -1, -1, -1, 0, 1, 1, 1};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            long long rolls = 0;
            for (int k = 0; k < 8; k++) {
                if (!isSafe(m, n, i + dI[k], j + dJ[k])) continue;
                if (grid[i + dI[k]][j + dJ[k]] == '@') rolls++; 
            }
            if (grid[i][j] == '@' && rolls < 4) total++;
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