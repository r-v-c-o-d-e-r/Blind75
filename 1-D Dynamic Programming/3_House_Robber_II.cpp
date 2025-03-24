#include<vector>
using namespace std;

class Solution {
public:
    int robSolution(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0], prev2 = 0;

        for(int i=1; i<n; i++){
            int pick = nums[i] + prev2, notPick = prev1;
            prev2 = prev1;
            prev1 = max(pick, notPick);
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> temp1(nums.begin(),nums.end()-1);
        vector<int> temp2(nums.begin()+1, nums.end());
        return max(robSolution(temp1), robSolution(temp2));
    }
};
    