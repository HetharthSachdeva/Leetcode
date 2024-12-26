class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i = 0; i < n; i++){
            if(ans.size()==0) ans.push_back(intervals[i]);
            else{
                vector<int> k = ans[ans.size()-1];
                if(intervals[i][0] <= k[1]){
                    ans[ans.size()-1][1] = max(intervals[i][1],k[1]);
                }
                else ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};