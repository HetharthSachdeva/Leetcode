class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int pro = 0;
        int ma = 0;
        for(int i= 1;i < prices.size(); i++){
            if(prices[i]-prices[buy] > 0) pro+=prices[i]-prices[buy];
            buy = i;
        }
        return pro;
    }
};