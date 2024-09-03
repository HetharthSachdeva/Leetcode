class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long pre[n];
        if(n==1 && nums[0]!=k) return 0;
        long long sum = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            sum+=nums[i];
            pre[i] = sum;    
            if(sum==k) count++;
        }
        
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(pre[j]-pre[i] == k) count++;
            }
        }
        return count;
    }
};