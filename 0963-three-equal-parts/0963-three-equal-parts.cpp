class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int ones = 0;
        for(int i : arr) if(i==1) ones++;
        if(ones%3 != 0) return {-1,-1};
        int n = arr.size();
        if(ones==0) return {0,n-1};

        // for(int i =n-1; i >= 0; i--){
        //     if(arr[i]==1) break;
        //     ze++;
        // }
        int i = -1, j = -1, k = -1;
        int o = 0;
        for(int l = 0; l < n; l++){
            if(arr[l]==1) o++;
            if(arr[l] == 1 && i==-1) i = l;
            else if(arr[l] == 1 && o == (ones/3)+1 && j==-1) j = l;
            else if(arr[l] == 1 && o == 2*(ones/3) +1){
                k = l ;
                break;
            } 
        }
        // return{i,j,k};
        while(k < n){
            if(arr[i]!=arr[j] || arr[i]!=arr[k]) return {-1,-1};
            i++;
            j++;
            k++;
        }
        return {--i,j};
    }
};