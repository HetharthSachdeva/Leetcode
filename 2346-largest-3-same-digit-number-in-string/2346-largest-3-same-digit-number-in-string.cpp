class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i = 0; i < (int)num.size()-2; i++){
            if((num[i]==num[i+1]) && (num[i]==num[i+2])){
                if((ans.size()==0) || (ans[0]<num[i])){
                    ans = num[i];
                    ans+=num[i];
                    ans+=num[i];
                }
            }
        }
        return ans;
    }
};