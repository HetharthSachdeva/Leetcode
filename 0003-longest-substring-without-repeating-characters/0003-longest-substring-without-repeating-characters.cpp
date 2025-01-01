class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        int max = 0;
        map<char, int> m;
        int i = 0, j = 0;
        while(j < n){
            
            if(m[s[j]] == 1){
                m[s[i]]--;
                i++;
            }
            else{
                m[s[j]]++;
                if(max < j-i+1) max = j-i+1;
                j++;
                
            }

        }
        return max;
    }
};