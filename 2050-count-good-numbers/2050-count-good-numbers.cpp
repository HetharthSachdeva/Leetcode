class Solution {
public:
    long long MOD = 1e9 + 7;
    long long power(long long a, long long b){
        if(b==0) return 1;
        if(b&1) return (a*power((a*a)%MOD,b/2))%MOD;
        return (power((a*a)%MOD,b/2))%MOD;
    }
    int countGoodNumbers(long long n) {
        if(n==1) return 5;
        return (power(5,(n+1)/2)%MOD * power(4,n/2)%MOD);
    }
};