class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int, int> hash;
        int k = banned.size();
        for(int i = 0; i < k; i++) hash[banned[i]] = i;
        int c= 0;
        for(int i = 1;i <= n; i++){
            if(hash.find(i)==hash.end()){
                maxSum -= i;
                if(maxSum < 0) return c;
                else if(maxSum == 0) return ++c;
                else c++;
            }
        }
        return c;

    }
};