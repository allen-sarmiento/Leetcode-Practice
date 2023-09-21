#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

bool cmpFirst(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

bool cmpSecond(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

bool cmpFirstSecond(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second > p2.second;
    return p1.first > p2.first;
}

bool cmpSecondFirst(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) return p1.first > p2.first;
    return p1.second > p2.second;
}

int main() {
    
    srand(time(NULL));
    vector<pair<int, int>> pairs;
    int numPairs = 10, lastRnd1 = -1;
    bool copy = false;

    for (int i = 0; i < numPairs; i++) {
        int rnd1 = std::rand() % 201 + 100;
        int rnd2 = std::rand() % 201 + 100;
        if (copy) pairs.push_back(make_pair(lastRnd1, rnd2));
        else pairs.push_back(make_pair(rnd1, rnd2));
        copy = !copy;
        lastRnd1 = rnd1;
    }

    cout << "Unsorted: " << endl;
    for (int i = 0; i < numPairs; i++) {
        cout << pairs[i].first << ", " << pairs[i].second << endl;
    }

    cout << "\nSorted by First: " << endl;
    sort(pairs.begin(), pairs.end(), cmpFirst);
    for (int i = 0; i < numPairs; i++) {
        cout << pairs[i].first << ", " << pairs[i].second << endl;
    }

    cout << "\nSorted by First, then Second: " << endl;
    sort(pairs.begin(), pairs.end(), cmpFirstSecond);
    for (int i = 0; i < numPairs; i++) {
        cout << pairs[i].first << ", " << pairs[i].second << endl;
    }
}