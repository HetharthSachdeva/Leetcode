class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> minHeap(nums.begin(), nums.end());
        k--;
        while(k--){
            minHeap.pop();
        }

        return minHeap.top();
    }
};