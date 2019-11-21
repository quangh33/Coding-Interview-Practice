//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    int distanceBetweenBusStops(vector<int> &a, int start, int destination) {
        int n = a.size();
        int s[n];
        s[0] = 0;
        for (int i = 1; i < n; i++) s[i] = a[i - 1] + s[i - 1];
        if (destination < start) swap(start, destination);

        int option1 = s[start] + a[n - 1] + s[n - 1] - s[destination];
        int option2 = s[destination] - s[start];
        return min(option1, option2);
    }
};