class Solution {
public:
    long set_bits(long x){
        if(x < 2) return x;
        return set_bits(x/2)+(x%2); 
    }
    int makeTheIntegerZero(int num1, int num2) {
        if(num1 == 0) return 0;
        if(num1 < num2+1) return -1;
        for(long i = 1; i < INT_MAX; i++){
            long u = set_bits((long)num1 - i*num2);
            if((long)num1 - i*num2 < i) return -1;
            if(u <=  i) return i;

        }
        return -1;
    }
};