class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int i = *max_element(weights.begin(), weights.end()), j = accumulate(weights.begin(), weights.end(), 0);
        while(i < j){
            int mid = i+(j-i)/2;
            int d = 0;
            int sum = 0;
            for(int i : weights){
                if(sum+i > mid){
                    d++;
                    sum = i;
                }
                else{
                    sum+=i;
                }
            }
            if(sum>0) d++;
            if(d > days) i = mid+1;
            else j = mid;
        }
        return i;
    }
};