#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

pair<int, int> findMax(string& bank, int start, int end) {
    int currMax = -1;
    int index = 0;
    
    for (int i = start; i <= end; i++) {
        if (bank[i] - '0' > currMax) {
            currMax = bank[i] - '0';
            index = i;
        }
    }
    
    return {currMax, index};
}

long long solve(vector<string>& banks) {
    long long total = 0;
    
    for (string bank: banks) {
        int toChoose = 12;
        int start = 0, end = bank.size() - toChoose;
        
        stringstream ss;
        while (toChoose) {
            pair<int, int> data = findMax(bank, start, end);
            ss << to_string(data.first);
            start = data.second + 1;
            end++;
            toChoose--;
        }
        
        total += stoll(ss.str());
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
    
    long long result = solve(banks);
    
    cout << result;
    
    return 0;
}