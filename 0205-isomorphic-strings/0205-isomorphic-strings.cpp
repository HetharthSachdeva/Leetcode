class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        set<char> a(s.begin(),s.end());
        set<char> b(t.begin(),t.end());
        if(a.size()!=b.size()) return false;
        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) == m.end()) m[s[i]] = t[i];
            else{
                if(m[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};