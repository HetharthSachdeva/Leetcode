class Solution {
public:
    string answerString(string word, int numFriends) {
        char ma = word[0];
        vector<int> pos;
        int n = word.size();
        if(numFriends==1) return word;
        pos.push_back(0);
        for(int i = 1; i < word.size(); i++){
            if(word[i] > ma){
                ma = word[i];
                pos.clear();
                pos.push_back(i);
            }
            else if(word[i]==ma) pos.push_back(i);
        }

        string ans(1,ma);
        for(int i: pos){
            string temp = word.substr(i, min(n-numFriends+1, n-i));
            if(temp > ans) ans = temp;
        }
        return ans;
    }
};