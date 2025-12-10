#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long long x;
    long long y;
};

long long solve(vector<Point>& tiles) {
    long long maxArea = 0;
    int n = tiles.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long left = min(tiles[i].x, tiles[j].x);
            long long right = max(tiles[i].x, tiles[j].x);
            long long bottom = min(tiles[i].y, tiles[j].y);
            long long top = max(tiles[i].y, tiles[j].y);

            long long currentArea = (right - left + 1) * (top - bottom + 1);
            if (currentArea <= maxArea) continue;

            bool possible = true;
            // Edge must cut through the rectangle
            for (int k = 0; k < n; k++) {
                Point p1 = tiles[k];
                Point p2 = tiles[(k + 1) % n];

                // Vertical Edge
                if (p1.x == p2.x) {
                    // If inside rectangle X range
                    if (p1.x > left && p1.x < right) {
                        // Overlaps with rectangle Y range
                        if (max(bottom, min(p1.y, p2.y)) < min(top, max(p1.y, p2.y))) {
                            possible = false;
                            break;
                        }
                    }
                }
                // Horizontal Edge
                else {
                    // If inside rectangle Y range
                    if (p1.y > bottom && p1.y < top) {
                        // Overlaps with rectangle X range
                        if (max(left, min(p1.x, p2.x)) < min(right, max(p1.x, p2.x))) {
                            possible = false;
                            break;
                        }
                    }
                }
            }
            if (!possible) continue;

            // Center of the rectangle is inside the polygon
            double cx = (left + right) / 2.0;
            double cy = (bottom + top) / 2.0;
            bool onBoundary = false;
            int rayHits = 0;

            for (int k = 0; k < n; k++) {
                Point p1 = tiles[k];
                Point p2 = tiles[(k + 1) % n];

                // Vertical Edge
                if (p1.x == p2.x) {
                    // If center lies on this edge
                    if (abs(p1.x - cx) < 1e-9 && cy >= min(p1.y, p2.y) && cy <= max(p1.y, p2.y)) {
                        onBoundary = true;
                        break;
                    }
                    // >.< Ray Casting (counting vertical edges to the right of center)
                    if (p1.x > cx && cy >= min(p1.y, p2.y) && cy < max(p1.y, p2.y)) {
                        rayHits++;
                    }
                }
                // Horizontal Edge
                else {
                    // If center lies on this edge
                    if (abs(p1.y - cy) < 1e-9 && cx >= min(p1.x, p2.x) && cx <= max(p1.x, p2.x)) {
                        onBoundary = true;
                        break;
                    }
                }
            }
            // On boundary or inside
            if (onBoundary || (rayHits % 2 != 0)) maxArea = currentArea;
        }
    }

    return maxArea;
}

int main() {
    vector<Point> tiles;
    string line;

    while (getline(cin, line)) {
        if (line == "stop") break;

        stringstream ss(line);
        long long x = -1, y = -1;
        string token;
        while (getline(ss, token, ',')) {
            if (x == -1) x = stoll(token);
            else y = stoll(token);
        }
        tiles.push_back({x, y});
    }

    cout << solve(tiles);

    return 0;
}