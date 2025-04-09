class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = k, j = arr.size()+k+1;
        while(i < j){
            int mid = i+(j-i)/2;
            int a = 0, b = j-k;
            bool flag = false;
            while(a<b){
                int ind = a + (b-a)/2;
                if(ind >= arr.size()){
                    
                    break;
                }
                if(arr[ind] == mid){
                    if(ind +k >= mid){
                        i = mid+1;
                    }
                    else{
                        j = mid-1;
                    }
                    flag = true;
                    break;
                }
                else if(arr[ind] < mid){
                    a = ind+1;
                }
                else b = ind;
            }
            if(!flag){
                if(a + k == mid){
                    return mid;
                }
                else if(a + k > mid){
                    i = mid+1;
                }
                else j = mid;
            }    
        }
        return i;
    }
};