#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool isInvalid(string k) {
    long long n = k.size();
    
    // Sliding Window
    for (long long w = 1; w <= n / 2; w++) {
        if (n % w != 0) continue; 
        string primary = k.substr(0, w);
        
        bool success = true;
        for (long long i = w; i < n; i += w) {
            string secondary = k.substr(i, w);
            if (primary != secondary) {
                success = false;
                break;
            }
        }
        
        if (success) return false;
    }
    
    return true;
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