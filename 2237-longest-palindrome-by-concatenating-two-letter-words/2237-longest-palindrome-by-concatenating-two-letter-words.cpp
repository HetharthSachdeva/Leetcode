class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int a = 0, b = 0;
        map<string, int> f;
        for(string word : words){
            f[word]++;
        }
        bool flag = false;
        for(auto [word,no] : f){
            if(word[0]==word[1]){
                if(f[word]&1) flag = true;
                b+= f[word]/2;
            }
            else{
            string temp = word;

            reverse(temp.begin(), temp.end());
            if(f.find(temp)!=f.end()) a+=min(f[temp], f[word]);
            }
        }
        return 2*a + 4*b + 2*flag;
    }
};