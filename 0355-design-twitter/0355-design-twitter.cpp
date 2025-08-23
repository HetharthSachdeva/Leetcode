class Twitter {
public:
    vector<vector<int>> tweets;
    map<int, set<int>> adj;
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(int i = tweets.size()-1; i>= 0; i--){
            if(ans.size()>=10) break;
            if((tweets[i][0] == userId) ||(adj[userId].find(tweets[i][0]) != adj[userId].end())) ans.push_back(tweets[i][1]) ;
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