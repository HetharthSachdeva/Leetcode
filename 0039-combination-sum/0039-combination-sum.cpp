class Solution {
public:
    vector<vector<int>> ans;
    void print(vector<int> a, int sum, int t, vector<int> b,int l){
        if(sum > t) return;
        if(sum == t){
            sort(b.begin(),b.end());
            ans.push_back(b);
            return;
        }
        if(l>=a.size()) return;
        for(int i = l;  i < a.size(); i++){
            b.push_back(a[i]);
            print(a,sum+a[i],t,b,i);
            b.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        print(candidates, 0, target, {}, 0);
        
        
        return ans;
    }
};