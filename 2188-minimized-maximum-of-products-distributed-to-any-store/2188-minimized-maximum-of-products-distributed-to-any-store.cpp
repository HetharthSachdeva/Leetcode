class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int q = quantities.size();
        int ma = *max_element(quantities.begin(),quantities.end());
        int i = 1, j = ma; int ans = 1;
        while(i <= j){
            int mid = i+(j-i)/2;
            int l = 0;
            for(int k = 0; k < q; k++){
                l+= (quantities[k]+mid-1)/mid;
            }
            if(l > n) i = mid+1;
            else{
                ans = mid;
                j = mid-1;
            }
        }
        return ans;
    }
};