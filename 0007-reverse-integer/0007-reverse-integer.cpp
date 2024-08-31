class Solution {
public:
    int reverse(int x) {
       int rev = 0;
       signed l = INT_MIN;
       signed r = INT_MAX;
        if(x<0){
            while(x<0){
            if(rev>(r/10) || rev<(l/10))
            return 0;    
            rev*=10;
            rev -= x%10;
            x/=10;
            
       
       }
       
       return -rev;
        }
       while(x>0){
            if(rev>(r/10) || rev<(l/10))
            return 0;
            rev*=10;
            rev+=x%10;
            x/=10;
            
       
       }
       
       return rev;
    }   
};
    