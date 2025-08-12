class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int ans = 0;
        
        unordered_map<int, int> m;
        for(auto i : nums){
            sum += i;
            
            if(sum == goal) ans++;
            if(m.find(sum -goal)!=m.end()){
                ans += m[sum-goal];
            }
            m[sum]++;
        }

        return ans;
    }
};