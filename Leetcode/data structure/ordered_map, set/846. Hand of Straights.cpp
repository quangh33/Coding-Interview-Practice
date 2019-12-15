//
// Created by Hoang, Quang on 2019-08-27.
//

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> count;
        for(int h: hand) count[h]++;
        while (count.size() > 0) {
            int smallestHand = (*count.begin()).first;
            for(int i = smallestHand; i <= smallestHand + W - 1; i++) {
                if (count[i] == 0) return false;
                count[i]--;
                if (count[i] == 0) count.erase(i);
            }
        }
        return true;
    }
};