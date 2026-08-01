class tweet {
public:
    int tweetid;
    int time;
    tweet(int id, int t) {
        this->tweetid = id;
        this->time = t;
    }
};

class comp {
public:
    bool operator()(const tweet &a, const tweet &b) {
        return a.time > b.time;   // Min Heap
    }
};

class Twitter {
public:
    int time = 0;
    // user -> tweets
    unordered_map<int, vector<tweet>> tweets;
    // user -> people he follows
    unordered_map<int, unordered_set<int>> following;
    Twitter() {
        time = 0;
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(tweet(tweetId, time));
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tweet, vector<tweet>, comp> pq;
        // Add user's own tweets
        if (tweets.find(userId) != tweets.end()) {
            for (auto &t : tweets[userId]) {
                pq.push(t);
                if (pq.size() > 10)
                    pq.pop();
            }
        }

        // Add tweets from followees
        if (following.find(userId) != following.end()) {
            for (auto followeeId : following[userId]) {
                if (tweets.find(followeeId) != tweets.end()) {
                    for (auto &t : tweets[followeeId]) {
                        pq.push(t);
                        if (pq.size() > 10)
                            pq.pop();
                    }
                }
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().tweetid);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        following[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if (following.find(followerId) != following.end()) {
            following[followerId].erase(followeeId);
        }
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