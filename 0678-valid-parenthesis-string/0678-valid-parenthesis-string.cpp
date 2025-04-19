class Solution {
public:
    bool checkValidString(string s) {
        int mi = 0, ma = 0;
        for(char f : s){
            if(f=='('){
                mi++;
                ma++;
            }
            else if(f==')'){
                mi--;
                ma--;
            }
            else{
                mi--;
                ma++;
            }

            if(mi < 0){
                if(ma < 0) return false;
                else mi = 0;
            }
        }   

        return mi == 0;
    }
};