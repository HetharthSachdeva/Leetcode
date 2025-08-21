class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        vector<int> f;
        for(char c: tasks) m[c]++;
        for(auto i: m) f.push_back(i.second);

        sort(f.begin(), f.end());
        int c = 0;
        for(int i = f.size()-1; i>= 0; i--){
            if(f[i]==f[f.size()-1]) c++;
            else break;
        } 

        return max((int)tasks.size(), ((f[f.size()-1]-1) * (n+1) + c));
    }
};