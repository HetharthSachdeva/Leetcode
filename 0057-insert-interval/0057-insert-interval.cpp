class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(newInterval);
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][1] < ans[ans.size() - 1][0]){
                vector<int> temp = ans[ans.size() -1];
                ans.pop_back();
                ans.push_back(intervals[i]);
                ans.push_back(temp);
               
            }
            else if(intervals[i][0] > ans[ans.size() - 1][1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans[ans.size()-1][0] = min(ans[ans.size() -1][0], intervals[i][0]);
                ans[ans.size()-1][1] = max(ans[ans.size() -1][1], intervals[i][1]);
            }
        }
        return ans;
    }
};