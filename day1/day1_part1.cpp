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
      current = (current + 100 - n) % 100;
    }
    else current = (current + n) % 100;
    
    if (current == 0) total++;
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