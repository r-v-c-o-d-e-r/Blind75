#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int val : nums){
            mp[val]++;
        }

        int n = nums.size();
        vector<vector<int>>bucket(n+1);
        for(auto [key,val] : mp){
            bucket[val].push_back(key);
        }

        for(int i=n; i>=0; i--){
            for(int j=0; j<bucket[i].size(); j++){
                ans.push_back(bucket[i][j]);
                k--;
                if(k == 0)
                return ans;
            }
        }
        return ans;
    }
};
    