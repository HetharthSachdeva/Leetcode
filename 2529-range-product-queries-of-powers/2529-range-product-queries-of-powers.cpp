class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans, powers;
        int k = 0;
        while(n>0){
            if(n%2 == 1){
                powers.push_back((int)pow(2, k));
            }
            n/=2;
            k++;
        }
        // vector<long long> pre;
        // long long sum = 1;
        // for(auto i : powers){
        //     sum*=i;
        //     sum%=(long long)(1e9 + 7);
        //     pre.push_back(sum);
        // }

        for(auto i : queries){
            long long sum = 1;
            for(int j = i[0]; j <= i[1]; j++){
                sum*=powers[j];
                sum%= (long long)(1e9+7);
            } 
            ans.push_back(sum);
        }
        return ans;
    }
};