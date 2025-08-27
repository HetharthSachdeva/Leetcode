class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++) nums[i] = (nums[i]%2);
        for(int i = 1; i < n; i++) nums[i]+=nums[i-1];
        int ans = 0;
        map<int, int> pre;
        for(int i = 0; i < n; i++){
            pre[nums[i]]++;
            if(nums[i] == k) ans++;
        }
        for(auto i: pre){
            if(pre.find(k+i.first) != pre.end()){
                ans+= i.second*pre[k+i.first];
            }
        }
        return ans;
    }
};