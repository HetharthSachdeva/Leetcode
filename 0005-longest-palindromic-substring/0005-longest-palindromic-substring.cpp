class Solution {
public:
    bool valid(string& t, int a, int b){
        int n = t.size();
        for(int i = 0; 2*i <= (b-a); i++){
            if(t[a+i]!=t[b-i]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = n; i > 0; i--){
            for(int j = 0; j < n-i+1; j++)
                if(valid(s,j,j+i-1)) return s.substr(j,i);
        }
        return "";
    }
};