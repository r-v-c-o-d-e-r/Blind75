#include<vector>
#include<string>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(string& str : strs){
            result += to_string(str.length()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string>result;
        int i =0;
        while(i < s.length()){
            int j = i;
            while(s[j] != '#')
            j++;

            int len = stoi(s.substr(i,j-i));
            result.push_back(s.substr(j+1,len));
            i = j + 1 + len;
        }
        return result;
    }
};
    