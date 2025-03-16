class Solution {
public:
    bool safe(vector<string>& l, int r, int c){
        // if(l[r][c] == 'Q') return false;
        
        for(int i = 0; i < l.size(); i++){
            if(l[r][i]=='Q') return false;
            if(l[i][c] == 'Q') return false;
        }

        int i = r, j = c;
        while(i < l.size() && j < l.size()){
            if(l[i][j]=='Q') return false;
            i++;
            j++;
        }

        i = r, j = c;
        while(i >= 0 && j >= 0){
            if(l[i][j]=='Q') return false;
            i--;
            j--;
        }

        i = r, j = c;
        while(i < l.size() && j >= 0){
            if(l[i][j]=='Q') return false;
            i++;
            j--;
        }
        i = r, j = c;
        while(i >= 0 && j < l.size()){
            if(l[i][j]=='Q') return false;
            i--;
            j++;
        }

        return true;
    }
    void helper(vector<string> p, int ind, vector<vector<string>>& a){
        if(ind >= p.size()){
            a.push_back(p);
            return;
        } 
        bool done = false;
        for(int i = 0; i < p.size(); i++){
            if(safe(p,ind, i)){
                p[ind][i] = 'Q';
                helper(p, ind+1, a);
                p[ind][i] = '.';
                done = true;
            }
        }
        if(!done) return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> place(n , string(n,'.'));
        vector<vector<string>> ans;
        // if(n==1) return {{'Q'}};
        helper(place, 0, ans);
        return ans;
    }
};