class Solution {
public:
    void print(vector<string> &v,string s, int n, int k, int a){
        if(k>= 2*n){
            if(a==0) v.push_back(s);
            return;
        }
        
        
        if(a < n){
            print(v,s+'(',n,k+1,a+1);
        }
        // s.erase(s.size()-1);

        if(a>0){
            print(v,s+')',n,k+1,a-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        print(ans, "", n, 0, 0);
        return ans;
    }
};