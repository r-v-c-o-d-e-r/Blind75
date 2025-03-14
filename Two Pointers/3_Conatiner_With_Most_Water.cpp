#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low = 0, high = heights.size() - 1;
        int area = 0;
        while(low < high){
            area = max(area, 
            min(heights[low],heights[high]) * (high - low));

            if(heights[low] <= heights[high])
            low++;
            else
            high--;
        }
        return area;
    }
};
    