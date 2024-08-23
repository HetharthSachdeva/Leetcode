class Solution {
public:
    void bubblesort(vector<int>& n){
        for(int i = 0; i < n.size()-1; i++){
            for(int j = 0;j < n.size()-1-i; j++){
                if(n[j] > n[j+1]) swap(n[j],n[j+1]);
            }
        }
    }
    void sortColors(vector<int>& nums) {
        bubblesort(nums);
    }
};