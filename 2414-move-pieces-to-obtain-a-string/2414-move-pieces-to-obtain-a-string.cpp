class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        int n = start.size();
        
        while(i < n && j < n){
            if(start[i] == '_'){
                i++;
                continue;
            }
            if(target[j]=='_'){
                j++;
                continue;
            }
            if(start[i]!=target[j]){
                return false;
            }
            else{
                if(start[i]=='L'){
                    if(j-i > 0) return false;
                    else {
                        i++;
                        j++;
                    }
                }
                else{
                    if(j-i <0) return false;
                    else{
                        i++;
                        j++;
                    }
                }
            }
        }
        if(i < n){
            while(i<n){
                
                if(start[i]!='_') return false;
                i++;
            }
        }
        if(j < n){
            while(j < n){
                if(target[j]!='_' ) return false;
                j++;
            }
        }
        return true;
    }
};