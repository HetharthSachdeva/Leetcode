class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int i = 0, spaces = 0;
        string h = "";
        while(i<n){
            if(sentence[i]==' '){
                h = "";
                spaces++;
            }
            else{
                 h+=sentence[i];
                 if(h == searchWord) return ++spaces;
            }
            i++;
        }
        return -1;
    }
};