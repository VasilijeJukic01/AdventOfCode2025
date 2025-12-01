#include <iostream>
#include <vector>

using namespace std;

int solve(vector<string>& rotations) {
  int total = 0;
  int current = 50;
  
  for (int i = 0; i < rotations.size(); i++) {
    int n = 0;
    
    for (int k = 1; k < rotations[i].size(); k++) {
      n = n * 10 + rotations[i][k] - '0';
    }
    
    if (rotations[i][0] == 'L') {
      int dist = (current == 0) ? 100 : current;

      if (n >= dist) {
          total += (n - dist) / 100 + 1;
      }

      current = ((current - n) % 100 + 100) % 100;
    }
    else {
      total += (current + n) / 100;
      current = (current + n) % 100;
    }
  }
  
  return total;
}

int main() 
{
    vector<string> rotations;
    string x;
    
    while (cin >> x) {
        rotations.push_back(x);
    }
    
    int total = solve(rotations);
    
    cout << total;
    
    return 0;
}