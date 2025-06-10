class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub; int ans = 1;sub.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i]>sub[sub.size()-1]){
                sub.push_back(nums[i]);
                if(ans<sub.size()) ans =  sub.size();
            } 
            else{
                int a = 0, b = sub.size()-1;
                while(a<=b){
                    int mid = a+(b-a)/2;
                    if(sub[mid]>=nums[i]) b=mid-1;
                    else a = mid+1;
                }
                sub[a] = nums[i];
            }
        }     
        return ans;
    }    
};