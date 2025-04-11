class Solution {
public:
    bool isPowerOfTwo(int n) {
        int c = 0;
        while(n>0){
            n&=(n-1);
            c++;
        }
        return c==1;
    }
};