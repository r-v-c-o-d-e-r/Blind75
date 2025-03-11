#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int xorVal = 0;
        for(int i=1; i<=size; i++){
            xorVal ^= (i ^ nums[i-1]);
        }
        return xorVal;
    }
};
    