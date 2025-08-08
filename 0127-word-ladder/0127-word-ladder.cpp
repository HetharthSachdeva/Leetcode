class Solution {
public:
    int check(string& a, string& b){
        int k = a.size(), y = 0;
        for(int i = 0; i < k; i++){
            if(a[i]!=b[i]) y++;
        }

        return y;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag = true;
        for(auto s: wordList){
            if(s==endWord){
                flag = false;
                break;
            }
        }
        if(flag) return 0;
        queue<string> q;
        int k = wordList.size();
        q.push(beginWord);
        vector<bool> v(k, false);
        int ans = 0;
        if(beginWord==endWord) return 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                string g = q.front();
                if(g==endWord){
                    return ans+1;
                }
                q.pop();
                for(int i = 0; i < k; i++){
                    if(!v[i] && check(g, wordList[i])==1){
                        q.push(wordList[i]);
                        v[i] = true;
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};