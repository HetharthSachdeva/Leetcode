class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> f;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            f[nums[i]]++;
        }
        for(int i = 1; i < INT_MAX; i++){
            if(f.find(i) == f.end()){
                return i;
            }
        }
        return 1;
    }
};