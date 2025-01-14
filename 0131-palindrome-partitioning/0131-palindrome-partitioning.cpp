class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> all;

    void help(string a, vector<string> combo, int i){
        if(i==a.size()){
            all.push_back(combo);
            return;
        }
        
        if(combo.size()==0){
            combo.push_back(string(1,a[i]));
            help(a, combo, i+1);
        }
        else{
            combo.push_back(string(1,a[i]));
            help(a, combo, i+1);
            combo.pop_back();
            combo[combo.size()-1]+=a[i];
            help(a, combo, i+1);
        }
    }
    bool ispalindrome(string e){
        int n = e.size();
        for(int i = 0; i <= n/2; i++){
            if(e[i] != e[n-i-1]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        if(s.size()==1){
            return {{s}};
        }
        vector<string> c;
        help(s, c, 0);
        for(int i = 0; i < all.size(); i++){
            bool done = true;
            for(int j = 0; j < all[i].size(); j++){
                if(!ispalindrome(all[i][j])){
                    done = false;
                    break;
                }
            }
            if(done) ans.push_back(all[i]);

        }
        return ans;
    }
};