class Solution {
public:
    int maxDepth(string s) {
        int max = 0;
        int n = s.size();
        int c = 0;
        for(int i = 0 ; i < n; i++){
            if(s[i] == '(') c++;
            else if(s[i]==')') c--;
            if(max < c) max = c;
        }
        return max;
    }
};