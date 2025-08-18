class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> maxHeap;map<int, int> m;
        for(int i = 0; i < score.size(); i++){
            maxHeap.push(score[i]);
            m[score[i]] = i;
        } 
        map<int, string> medals = {{1,"Gold Medal"}, {2,"Silver Medal"},{3, "Bronze Medal"}};
        vector<string> ans(score.size());      
        for(int i = 0; i < score.size(); i++){
            int l =  m[maxHeap.top()];
            if(i < 3){
                ans[l] = medals[i+1];
            }
            else ans[l] = to_string(i+1);

            maxHeap.pop();
        }
        return ans;
    }
};