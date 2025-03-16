class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int r = ranks.size();
        sort(ranks.begin(),ranks.end());

        long long i = 0, j = LLONG_MAX, ans =j;
        while(i<=j){
            long long mid = i+(j-i)/2;
            long long k = 0;
            for(int i = 0; i < r; i++){
                k+= sqrt(mid/ranks[i]);
            }
            if(k >= cars){
                ans = mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        return ans;
    }
};