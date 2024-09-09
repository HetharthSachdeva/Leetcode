class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans;
        int c1 = 0, c2 = 0, e1 = 0, e2 = 0;
        for(int i: nums){
            if(c1 == 0 && i!=e2){
                c1++;
                e1 = i;
            }
            else if(c2 == 0 && i!=e1){
                c2++;
                e2 = i;
            }
            else if(e1 == i) c1++;
            else if(e2 == i) c2++;
            else{
                c1--;
                c2--;
            }
        }
        c1 = 0; c2 =0;
        for(int j: nums){
            if(j==e1) c1++;
            else if(j==e2) c2++;
        }
        int n = nums.size();
        if(c1>n/3) ans.push_back(e1);
        if(c2> n/3) ans.push_back(e2);
        return ans;

    }
};