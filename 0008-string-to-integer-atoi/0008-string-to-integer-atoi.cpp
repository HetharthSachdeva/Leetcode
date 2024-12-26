class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int n = s.size();
        bool start = false;
        int f = 1;
        for(int i = 0; i < n; i++){
            if(s[i]<='9' && s[i]>='0'){
                start = true;
                ans*=10;
                if(ans > INT_MAX || ans<INT_MIN) break;
                ans+=s[i]-'0';
            }
            else if(start){
                break;
            }
            else{
                if(s[i] == ' ' ) continue;
                else if(s[i] == '-'){
                    start = true;
                    f = -1;
                }
                else if(s[i] == '+') start = true;
                else break;
            }
        }
        ans*=f;
        if(ans < INT_MIN) return INT_MIN;
        else if(ans > INT_MAX) return INT_MAX;
        return ans;
    }
};