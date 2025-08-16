class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        if(a[0] != b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int ans = 0, b = INT_MIN;
        for(auto i : intervals){
            if(i[0]>=b){
                ans++;
                b = i[1];
            }
            else{
                if(i[1]<b){
                    b = i[1];
                }
            }
        }
        return intervals.size()-ans;
    }
};