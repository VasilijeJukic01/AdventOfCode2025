#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

// Building block for a shape
struct Point {
    int row;
    int col;

    bool operator<(const Point& o) const {
        return row < o.row || (row == o.row && col < o.col);
    }
};

vector<vector<vector<Point>>> shapes;
vector<vector<int>> grid;
int H, W;

// Shifts the shape so its top left block is at (0, 0)
// Prevents negative values during rotation
vector<Point> fixShape(vector<Point> v) {
    int minRow = 1e9, minCol = 1e9;

    for (Point& p : v) {
        minRow = min(minRow, p.row);
        minCol = min(minCol, p.col);
    }
    for (Point& p : v) {
        p.row -= minRow;
        p.col -= minCol;
    }

    sort(v.begin(), v.end());

    return v;
}

void generateShapes(int id, vector<Point>& points) {
    set<vector<Point>> unique;
    vector<Point> cur = points;

    for (int flip = 0; flip < 2; flip++) {
        for (int rotation = 0; rotation < 4; rotation++) {
            unique.insert(fixShape(cur));
            // Rotate 90
            for (Point& p : cur) {
                int t = p.row;
                p.row = p.col;
                p.col = -t;
            }
        }
        // Flip
        for (Point& p : cur) {
            p.col = -p.col;
        }
    }

    if (shapes.size() <= id) {
        shapes.resize(id + 1);
    }

    shapes[id].assign(unique.begin(), unique.end());
}

bool solve(vector<int>& need, int currPresent, int lastRow, int lastCol) {
    if (currPresent == need.size()) return true;
    int id = need[currPresent];

    int startRow = 0, startCol = 0;
    // My little life saver <3 if pieces are identical
    if (currPresent > 0 && need[currPresent] == need[currPresent - 1]) {
        startRow = lastRow;
        startCol = lastCol;
    }

    for (int row = startRow; row < H; row++) {
        for (int col = (row == startRow ? startCol : 0); col < W; col++) {
            if (grid[row][col]) continue;

            for (vector<Point>& shape : shapes[id]) {
                bool valid = true;
                for (Point& p : shape) {
                    int gridRow = row + p.row;
                    int gridCol = col + p.col;
                    if (gridRow >= H || gridCol >= W || grid[gridRow][gridCol]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    // Place shape on grid
                    for (Point& p : shape) {
                        grid[row + p.row][col + p.col] = 1;
                    }
                    // Place next item
                    if (solve(need, currPresent + 1, row, col)) return true;
                    // Backtrack
                    // If piece doesnt fit remove, flip/rotate and try again
                    for (Point& p : shape) {
                        grid[row + p.row][col + p.col] = 0;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    string line;
    vector<string> lines;

    while (getline(cin, line)) {
        if (line == "stop") break;
        if (!line.empty()) lines.push_back(line);
    }

    int cur = -1, r = 0, total = 0;
    vector<Point> buffer;

    for (string& s : lines) {
        if (s.find("x") != string::npos && s.find(":") != string::npos) {
            if (cur != -1) {
                generateShapes(cur, buffer);
                cur = -1;
                buffer.clear();
            }

            int x = s.find('x');
            int col = s.find(':');
            W = stoi(s.substr(0, x));
            H = stoi(s.substr(x + 1, col - x - 1));

            stringstream ss(s.substr(col + 1));
            vector<int> need;
            int n, id = 0, area = 0;
            while (ss >> n) {
                while (n) {
                    need.push_back(id);
                    area += shapes[id][0].size();
                    n--;
                }
                id++;
            }

            if (area <= W * H) {
                sort(need.begin(), need.end(), [](int a, int b) {
                    return shapes[a][0].size() > shapes[b][0].size();
                });
                grid.assign(H, vector<int>(W, 0));
                if (solve(need, 0, 0, 0)) total++;
            }
        }
        else if (s.back() == ':') {
            if (cur != -1) {
                generateShapes(cur, buffer);
                buffer.clear();
            }
            cur = stoi(s.substr(0, s.size() - 1));
            r = 0;
        }
        else {
            for (int c = 0; c < s.size(); c++) {
                if (s[c] == '#') buffer.push_back({r, c});
            }
            r++;
        }
    }

    // Work pls :)
    cout << total;

    return 0;
}