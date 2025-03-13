#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;

        for(string str : strs){
            vector<int>charArray(26,0);
            string temp = "";
            for(char ch : str){
                charArray[ch -'a']++;
            }
            for(int val : charArray){
                temp += to_string(val) + ',';
            }
            mp[temp].push_back(str);
        }

        for(auto [key,val] : mp){
            ans.push_back(val);
        }
        
        return ans;
    }
};
    