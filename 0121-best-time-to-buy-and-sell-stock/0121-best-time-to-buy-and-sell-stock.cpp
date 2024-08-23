class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int min = prices[0];
        int n = prices.size();
        for(int i = 0; i < n; i++){
            if(max < prices[i]-min){
                max = prices[i]-min;
            }
            if(prices[i]<min) min = prices[i];
        }
        return max;
    }
};