//
// Created by Hoang, Quang on 2019-12-15.
//

class Leaderboard {
public:
    unordered_map<int, int> point;
    map<int, unordered_set<int>, greater<int> > players;

    Leaderboard() {

    }

    // O(log n)
    void addScore(int playerId, int score) {
        if (score == 0) return;
        int currentPoint = point[playerId];
        players[currentPoint].erase(playerId);
        int newPoint = currentPoint + score;
        point[playerId] += score;
        players[newPoint].insert(playerId);
    }

    // O(k)
    int top(int K) {
        if (K == 0) return 0;
        int res = 0;
        int count = 0;
        for (auto pair: players) {
            if (K >= pair.second.size()) {
                K -= pair.second.size();
                res += pair.first * pair.second.size();
            } else {
                res += pair.first * K;
                break;
            }
        }
        return res;
    }

    // O(log n)
    void reset(int playerId) {
        int currentPoint = point[playerId];
        players[currentPoint].erase(playerId);
        point.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */