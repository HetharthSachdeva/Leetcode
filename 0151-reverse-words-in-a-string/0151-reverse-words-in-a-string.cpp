class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string c = "";
        int n = s.size();
        for(int i = 0; i <= n; i++){
            if(s[i]==' ' || s[i]=='\0'){
                if(c!="") v.push_back(c);
                c = "";
            }
            else c+=s[i];
        }

        string ans = "";
        for(int i = v.size()-1; i >= 0; i--){
            ans+= v[i];
            ans+=' ';
        }
        return ans.erase(ans.size()-1);
    }
};