class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        
        if(n>0){
            if(n&1)
            return x*myPow(x*x,n/2);
            return myPow(x*x,n/2);
        } 
        if(n<0){
            if(n&1)
            return myPow(1/(x*x),abs(n/2))/x;
            return myPow(1/(x*x),abs(n/2));
        }
        return 1;
    }
};