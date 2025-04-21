class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long sum = 0;
        long long mi = 0, ma =0;
        for(int i : differences){
            sum+=i;
            mi = min(mi, sum);
            ma = max(ma, sum);
        }

        return max(0LL,(upper - lower + 1) - (ma - mi));
    }
};