#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>seen;
        for(int val : nums){
            if(seen.count(val))
            return true;

            seen.insert(val);
        }
        return false;
    }
};
    