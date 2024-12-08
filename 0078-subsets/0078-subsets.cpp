class Solution {
public:
    vector<vector<int>> p;
    void sub(vector<int> a, int i, int n, vector<int> d){
        if(i >= n){
            p.push_back(d);
            return;
        }
        sub(a,i+1,n,d);
        d.push_back(a[i]);
        sub(a,i+1,n,d);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> q;
        int n = nums.size();
        sub(nums,0,n,q);
        sort(p.begin(),p.end());
        return p;
    }
};