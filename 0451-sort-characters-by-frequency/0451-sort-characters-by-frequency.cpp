class Solution {
public:
    string frequencySort(string s) {
        map<char, int> f;
        for(auto c: s) f[c]++;
        map<int, vector<char>> rf;
        for(auto i: f){
            rf[i.second].push_back(i.first);

        }
        vector<int> l;
        for(auto i : rf) l.push_back(i.first);
        sort(l.begin(),l.end());
        reverse(l.begin(),l.end());
        string ans = "";
        for(int i = 0 ; i < l.size(); i++){
            for(char j : rf[l[i]]){
                for(int k = 0; k < l[i]; k++) ans+=j;
            }
        }
        return ans;
    }
};