#include<vector>
using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length()) return false;
    
            vector<int>frequencyArray(26,0);
            for(int i=0; i<s.length(); i++){
                frequencyArray[s[i] - 'a']++;
                frequencyArray[t[i] - 'a']--;
            }
            for(int i=0; i<26; i++){
                if(frequencyArray[i] != 0) return false;
            }
            return true;
        }
    };
    