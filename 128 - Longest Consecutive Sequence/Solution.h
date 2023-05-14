/*
    Date: 5/13/2023
    Time Complexity: O(n)
    Space Complexity: O(1)

    To be finished...
*/

#include <vector>
#include <unordered_map>
#include <list>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    void seqMapInsert(unordered_map<int, pair<list<int>, list<int>>>& seqMap, int n, list<int> seq) {
        auto iter = seqMap.find(n);
        if (iter == seqMap.end() || seqMap[n].first.size() == 0) seqMap[n].first = seq;
        else seqMap[n].second = seq;
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        // Each list is in ascending order (greatest at the back)
        unordered_map<int, pair<list<int>, list<int>>> seqMap;
        
        for (auto setIter = nums.begin(); setIter != nums.end(); setIter++) {

            // Look for n in seqMap
            int n = *setIter;
            auto iter = seqMap.find(n);

            /*
                nums: 3 [5] 7 6 4
                nums: 5 3 [4]

                future back: 6
                future front: 4

                seqMap:
                    - 2: [3, 4, 5]
                    - 6: [3, 4, 5]
            */
            
            // n is in seqMap. Append n to the sequence and update seqMap
            if (iter != seqMap.end()) {                

                // If there is a second list
                if (iter->second.second.size() > 0) {
                    // If the order is first then second
                    if (iter->second.first.back()+1 == iter->second.second.front()-1) {
                        iter->second.first.push_back(n);
                        iter->second.first.merge(iter->second.second);
                    // Else if the order is second then first
                    } else {
                        iter->second.first.push_front(n);
                        iter->second.second.merge(iter->second.first);
                        iter->second.first = iter->second.second;
                        iter->second.second.clear();
                    }

                    int futureFront = iter->second.first.front()-1;
                    int futureBack = iter->second.first.back()+1;
                    seqMapInsert(seqMap, futureFront, iter->second.first);
                    seqMapInsert(seqMap, futureBack, iter->second.first);
                    seqMap.erase(n);
                
                // Else there is only one list
                } else {
                    if (n == iter->second.first.back()+1) {
                        // Insert back to seq
                        iter->second.first.push_back(n);
                        // Add new back to seqMap
                        seqMapInsert(seqMap, n+1, iter->second.first);
                    }
                    else {
                        // Insert front to seq
                        iter->second.first.push_front(n);
                        // Add new front to seqMap
                        seqMapInsert(seqMap, n-1, iter->second.first);
                    }
                    // Erase old front/back from seqMap
                    seqMap.erase(n);
                }
                
            // n is not in seqMap. Add a new sequence into seqMap
            } else {
                // Add future back
                seqMapInsert(seqMap, n+1, list<int>{n});
                // Add future front
                seqMapInsert(seqMap, n-1, list<int>{n});
            }
        }

        int maxLength = 0, curLength = 0;
        for (auto iter = seqMap.begin(); iter != seqMap.end(); iter++) {
            curLength = max(iter->second.first.size(), iter->second.second.size());
            if (curLength > maxLength) 
                maxLength = curLength;
        }

        return maxLength;
    }
};