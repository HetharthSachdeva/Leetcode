class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        map<int, int> pre;
        int xo = 0;
        for(int i = 0; i < arr.size(); i++){
            
            xo^= arr[i];
            pre[i] = xo;
        }
        int query = queries.size();
        for(int i = 0; i < query; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l==0){
                ans.push_back(pre[r]);
            }
            else
            ans.push_back(pre[r]^pre[l-1]);
        }
        return ans;
    }
};