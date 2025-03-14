#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = -1;
        int maxProfit = 0;

        for(int i=n-1; i>=0; i--){
            if(prices[i] < maxi)
            maxProfit = max(maxProfit, (maxi - prices[i]));
            else
            maxi = prices[i];
        }
        return maxProfit;
    }
};
    