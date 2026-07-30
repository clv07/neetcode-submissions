class Twitter {
public:
    int timer = 0;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> [(time, tweetId)]
    unordered_map<int, unordered_set<int>> follows; // followerId -> {followeeId}

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq; // {time, userId, Idx}
        auto add = [&] (int user) {
            auto it = tweets.find(user);
            if (it != tweets.end() && !it->second.empty()) {
                int idx = it->second.size() - 1;
                pq.push({it->second[idx].first, user, idx});
            }
        };

        // only add the latest tweet to priority queue
        add(userId);
        for (int f: follows[userId]) add(f);

        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            auto [t, u, i] = pq.top();
            pq.pop();
            res.push_back(tweets[u][i].second);
            if (i > 0)
                pq.push({tweets[u][i-1].first, u, i-1});
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].erase(followeeId);
    }
};
