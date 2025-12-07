#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

long long solve(vector<string>& input) {
    long long total = 0;

    vector<vector<long long>> nums;
    vector<char> ops;

    for (int i = 0; i < input.size(); i++) {
        stringstream ss(input[i]);
        string token;
        int col = 0;
        
        while (ss >> token) {
            if (col >= nums.size()) {
                nums.resize(col + 1);
                ops.resize(col + 1, ' ');
            }
            if (token == "+" || token == "*") ops[col] = token[0];
            else nums[col].push_back(stoll(token));
            col++;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        long long sum = ops[i] == '+' ? 0 : 1;
        for (int j = 0; j < nums[0].size(); j++) {
            if (ops[i] == '+') sum += nums[i][j];
            else sum *= nums[i][j];
        }
        total += sum;
    }

    return total;
}

int main() {
    vector<string> input;

    string line;

    while (getline(cin, line)) {
        if (line == "stop") break;
        input.push_back(line);
    }

    cout << solve(input);

    return 0;
}