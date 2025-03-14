class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        int n = candies.size();

        for(int i : candies) sum+=i;

        if(sum < k) return 0;

        int i = 1, j = sum/k, ans = 1; 
        while(i <= j){
            int mid = i+(j-i)/2;
            long long l = 0;
            for(int i: candies) l+= i/mid;

            if(l >= k){
                ans = mid;
                i = mid+1;
            }  
            // else if(l>k) i = mid+1;
            else j=mid-1;
        }

        return ans;
    }
};