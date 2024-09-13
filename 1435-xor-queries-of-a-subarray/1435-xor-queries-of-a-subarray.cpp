class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans;

        map<int, int> pre;
        int xo = 0;
        int a = arr.size();
        for(int i = 0; i < a; i++){
            
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