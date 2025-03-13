#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int>st(nums.begin(),nums.end());
        int count = 1;

        for(int val : st){
            if(st.find(val - 1) == st.end()){
                int cnt = 1;
                while(st.find(val+1) != st.end() ){
                    cnt++;
                    val++;
                }
                count = max(count,cnt);
            }
        }
        return count;
    }
};
    