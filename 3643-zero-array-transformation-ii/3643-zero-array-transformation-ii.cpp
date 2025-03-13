class Solution {
public:
    bool check(vector<int> a, vector<int> b){
        for(int i = 0; i < a.size(); i++){
            if(a[i]+b[i]>0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long q = queries.size();
        long long n = nums.size();

        // long long sum = 0;
        // for(int i: nums) sum+= i;
        // if(sum == 0) return 0;
        int i = 0, j = q;
        int ans =-1;
        while(i <= j){
            int mid = i + (j-i)/2;
            vector<int> arr(n, 0);
            for(int k = 0; k < mid; k++){
                int a = queries[k][0], b = queries[k][1], c = queries[k][2];
                arr[a] -= c;
                if(b < n-1) arr[b+1] += c;
            }

            for(int k = 1; k < n; k++) arr[k]+= arr[k-1];

            if(check(arr, nums)){
                ans= mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        // if(i>q-1) return -1;
        return ans;
        
    }
};