class Solution {
public:
    long long maximumPoints(vector<int>& ee, int ce) {
        int n = ee.size();
        vector<bool> mark(n,false);
        sort(ee.begin(),ee.end());
        if(ee[0]> ce) return 0;
        long long ans = ce;
        for(int i = 1; i < n; i++){
            ans+=ee[i];
        }
        ans/=ee[0];
        return ans;
        
    }
};