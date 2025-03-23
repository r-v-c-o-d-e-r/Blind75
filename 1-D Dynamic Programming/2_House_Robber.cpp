#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0], prev2 = 0;

        for(int i=1; i<n; i++){
            int pick = nums[i] + prev2, notPick = prev1;
            prev2 = prev1;
            prev1 = max(pick, notPick);
        }
        return prev1;
    }
};
    