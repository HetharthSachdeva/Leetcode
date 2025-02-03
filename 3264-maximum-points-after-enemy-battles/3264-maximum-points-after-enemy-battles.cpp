class Solution {
public:
    long long maximumPoints(vector<int>& ee, int ce) {
        int n = ee.size();
        long long min = INT_MAX;
        long long sum = ce;
        for(int i = 0; i < n; i++){
            sum+=ee[i];
            if(ee[i]<min) min=ee[i];
        }

        if(min> ce) return 0;
        
        sum-=min;
        sum/=min;
        return sum;
        
    }
};