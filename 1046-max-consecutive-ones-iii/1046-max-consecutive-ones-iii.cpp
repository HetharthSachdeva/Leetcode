class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int i = 0, j = 0;
        int h = k;
        int n = nums.size();
        while(j < n){
            if(nums[j] == 1){
                 j++;
                 if(ans < j-i) ans = j-i;
            }
            else if(h > 0){
                j++;
                h--;
                if(ans < j-i) ans = j-i;
            }
            else{
                if(nums[i]==0){
                    i++;
                    h++;
                } 
                else i++;
            }
            

        }
        return ans;
    }
};