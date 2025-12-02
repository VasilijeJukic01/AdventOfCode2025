#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool isInvalid(string k) {
    if (k.size() & 1) return true;
    
    long long n = k.size();
    long long mid = n / 2;
    
    for (int i = 0, j = mid; j < n; i++, j++) {
        if (k[i] != k[j]) return true;
    }
    
    return false;
}

long long solve(vector<string>& ids) {
    long long total = 0;
    
    for (string range : ids) {
        stringstream ss(range);
        string left, right;
        
        getline(ss, left, '-');
        getline(ss, right);
        
        long long start = stoll(left);
        long long end = stoll(right);
        
        for (long long k = start; k <= end; ++k) {
            if (!isInvalid(to_string(k))) {
                total += k;
            }
        }
    }
    
    return total;
}

int main() 
{
    vector<string> ids;
    string x;
    
    cin >> x;
    
    stringstream ss(x);
    string item;
    while (getline(ss, item, ',')) {
        ids.push_back(item);
    }
    
    long long result = solve(ids);
    
    cout << result;
    
    return 0;
}