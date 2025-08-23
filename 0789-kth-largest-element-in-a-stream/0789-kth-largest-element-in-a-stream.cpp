class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> stream;
    KthLargest(int k, vector<int>& nums) {
        this->k = k; 
        for(int i = 0; i< (int)nums.size(); i++) stream.push(nums[i]);
        while(stream.size()>k){
            stream.pop();
        }
    }
    
    int add(int val) {
        if(stream.size() < k){
            stream.push(val);
        }
        else if(val > stream.top()){
            stream.pop();
            stream.push(val);
        }
        return stream.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */