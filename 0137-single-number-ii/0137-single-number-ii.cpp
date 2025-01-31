class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int , int> f;
        for(int i : nums) f[i]++;
        for(auto i : f) if(i.second == 1) return i.first;
        return -1;
    }
};