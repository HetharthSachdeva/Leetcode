class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        for(int i = 0; i< boxes.size(); i++){
            int k = 0;
            for(int j = 0; j < boxes.size(); j++){
                if(i==j) continue;
                if(boxes[j]=='1') k+= abs(j-i);
            }
            ans.push_back(k);
        }
        return ans;
    }
};