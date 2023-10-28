#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class TimeMap {
public:
    // Key: key  
    // Value: vector<pair<int, string>>
    //     -> int: timestamp
    //     -> string: value
    unordered_map<string, vector<pair<int, string>>> um;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        um[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // cout << "timestamp: " << timestamp << "\n";

        string res = "";
        if (um[key].size()) {

            int lp = 0, rp = um[key].size()-1;

            while (lp <= rp && lp >= 0 && lp < um[key].size() && rp >= 0 && rp < um[key].size()) {
                int mp = (lp+rp)/2;
                if (timestamp == um[key][mp].first) return um[key][mp].second;
                else if (timestamp > um[key][mp].first) {
                    res = um[key][mp].second;
                    lp = mp+1;
                }
                else rp = mp-1;
            }
            return res;
        } else return res;
    }
};

int main() {
    TimeMap tm;
    tm.set("love", "high", 10);
    tm.set("love", "low", 20);
    cout << tm.get("love", 5) << endl;      // ""
    cout << tm.get("love", 10) << endl;     // "high"
    cout << tm.get("love", 15) << endl;     // "high" x ""
    cout << tm.get("love", 20) << endl;     // "low"
    cout << tm.get("love", 25) << endl;     // "low"
    return 0;
}