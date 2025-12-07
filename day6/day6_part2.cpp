#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

long long solve(vector<string>& input) {
    size_t width = 0;

    for (int i = 0; i < input.size(); i++) {
        width = max(width, input[i].size());
    }
    for (int i = 0; i < input.size(); i++) {
        input[i].resize(width, ' ');
    }

    long long total = 0;
    vector<long long> nums;
    char currOp = ' ';
    bool inside = false;

    for (int x = 0; x < width; x++) {
        string num = "";
        char op = ' ';
        bool emptyCol = true;

        for (int y = 0; y < input.size(); y++) {
            char c = input[y][x];
            if (c != ' ') {
                emptyCol = false;
                if (isdigit(c)) num += c;
                else op = c;
            }
        }

        if (emptyCol) {
            if (inside) {
                long long result = (currOp == '+') ? 0 : 1;
                for (int i = 0; i < nums.size(); i++) {
                    if (currOp == '+') result += nums[i];
                    else result *= nums[i];
                }
                total += result;

                nums.clear();
                currOp = ' ';
                inside = false;
            }
        }
        else {
            inside = true;
            if (!num.empty()) nums.push_back(stoll(num));
            if (op != ' ') currOp = op;
        }
    }

    if (inside) {
        long long result = (currOp == '+') ? 0 : 1;
        for (int i = 0; i < nums.size(); i++) {
            if (currOp == '+') result += nums[i];
            else result *= nums[i];
        }
        total += result;
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