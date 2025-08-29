class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> f;
        for(auto i: nums) f[i]++;
        vector<vector<int>> v;
        for(auto i: f){
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(v[v.size()-1-i][1]);
        }
        return ans;
    }
};