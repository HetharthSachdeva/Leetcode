class Solution {
public:
    int reverse(int x) {
       long long rev = 0;
       signed l = INT_MIN;
       signed r = INT_MAX;
        if(x<0){
            while(x<0){
            rev*=10;
            rev -= x%10;
            x/=10;
       }
       if(rev>r || rev<l){
            return 0;
       }
       return -rev;
        }
       while(x>0){
            rev*=10;
            rev+=x%10;
            x/=10;
       }
       if(rev>r || rev<l){
            return 0;
       }
       return rev;
    }   
};