#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

pair<int, int> maxData(string& bank) {
    int currMax = -1;
    int index = 0;
    
    for (int i = 0; i < bank.size(); i++) {
        if (bank[i] - '0' > currMax) {
            currMax = bank[i] - '0';
            index = i;
        }
    }
    
    return {currMax, index};
}

int solve(vector<string>& banks) {
    int total = 0;
    
    for (string bank: banks) {
        int best = 0;
        pair<int, int> data = maxData(bank);
        
        // Left Side
        for (int i = 0; i < data.second; i++) {
            int n = (bank[i] - '0') * 10 + data.first;
            best = max(best, n);
        }
        // Right Side
        for (int i = data.second + 1; i < bank.size(); i++) {
            int n = data.first * 10 + (bank[i] - '0');
            best = max(best, n);
        }
        
        total += best;
    }
    
    return total;
}

int main() 
{
    vector<string> banks;
    string x;
    
    while (cin >> x) {
        if (x == "0") break;
        banks.push_back(x);
    }
    
    int result = solve(banks);
    
    cout << result;
    
    return 0;
}