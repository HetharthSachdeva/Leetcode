class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        ans+= (((long long)n/2) * ((long long)(m+1)/2));
        ans+= (((long long)(n+1)/2) * ((long long)m/2));
        return ans;
    }
};