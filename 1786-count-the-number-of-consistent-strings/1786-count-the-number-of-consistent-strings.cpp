class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        map<char, int> f;
        
        for(char i: allowed) f[i]++;
        int count = 0;
        for(auto i: words){
            bool consistent = true;

            for(char c: i){
                if(f[c]!=1){
                    consistent = false;
                    break;
                }
                
            }
            if(consistent) count++;
        }
        return count;
    }
};