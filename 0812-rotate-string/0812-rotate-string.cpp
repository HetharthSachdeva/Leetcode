class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n = s.size();
        for(int i = 0; i < n; i++){
            // string a = "";
            string b= s.substr(i,n-i);
            b+= s.substr(0,i);
            if(b == goal) return true;
        }
        return false;
    }
};