class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string digits;
        while(n>0){
            digits+=(n%10)+'0';
            n/=10;
        }
        sort(digits.begin(), digits.end());

        for(int i = 1; i < INT_MAX/2; i*=2){
            string a = to_string(i);
            sort(a.begin(), a.end());
            if(digits == a) return true;
        }

        return false;

    }
};