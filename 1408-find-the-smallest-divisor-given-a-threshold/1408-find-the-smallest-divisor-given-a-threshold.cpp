class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i = 1, j = INT_MAX;
        while(i <= j){
            int mid = i+(j-i)/2;
            long long tot = 0;
            for(int i : nums) tot += (i+mid-1)/mid;

            if(tot > threshold) i = mid+1;
            else j = mid-1;
        }
        return i;

    }
};