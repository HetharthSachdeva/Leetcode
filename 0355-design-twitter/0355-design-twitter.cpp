class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets; 
    unordered_map<int, unordered_set<int>> adj;int pos = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({pos++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> heap;
        vector<int> ans;
        for(auto i : tweets[userId]) heap.push({i.first, i.second});
        for(auto i : adj[userId]){
            for(auto j : tweets[i]) heap.push({j.first, j.second});
        }
        int h = heap.size();
        for(int i = 0; i < min(10, h); i++){
            ans.push_back(heap.top()[1]);
            heap.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        adj[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        adj[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */