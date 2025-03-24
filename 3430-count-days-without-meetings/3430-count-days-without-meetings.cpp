class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(),meetings.end());
        
        vector<vector<int>> a;
        for(auto i: meetings){
            if(a.empty() || a[a.size()-1][1] < i[0]-1){
                a.push_back(i);
            }
            else a[a.size()-1][1] = max(i[1], a[a.size()-1][1]);
        }
        int count = a[0][0]-1;
        for(int i = 0; i < a.size()-1; i++){
            count+=a[i+1][0]-a[i][1] - 1;
        }
        count+= days - a[a.size()-1][1];
        return count;
    }
};