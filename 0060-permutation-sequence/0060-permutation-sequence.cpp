class Solution {
public:
    int factorial(int x){
        if(x<2) return 1;
        return x*(factorial(x-1));
    }
    string getPermutation(int n, int k) {
        string s = "";
        vector<bool> used(n, false);
        for(int i = n-1; i > 0; i--){
            int f = factorial(i);
            int j = (k+f-1)/f;
            // j=max(j,1);
            k=k%f;
            if(k==0) k =f;
            for(int l = 0; l < n; l++){
                if(!used[l]){ 
                    j--;
                    if(j==0){
                        used[l] = true;
                        
                        s+=('1'+l);
                        break;
                    }
                }
            }

            
        }
        for(int i = 0; i < n; i++){
            if(!used[i]){
                s+='1'+i;
                break;
            }
        }
        return s;
    }
};