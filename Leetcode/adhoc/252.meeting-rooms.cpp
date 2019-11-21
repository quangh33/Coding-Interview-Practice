class Solution {
public:
    typedef pair<int, int> ii;

    bool canAttendMeetings(vector <vector<int>> &intervals) {
        if (intervals.size() == 0) return true;
        vector <ii> meetings;
        for (auto i: intervals) meetings.push_back(ii(i[0], i[1]));
        sort(meetings.begin(), meetings.end());
        for (int i = 0; i < meetings.size() - 1; i++)
            if (meetings[i].second > meetings[i + 1].first) return false;
        return true;
    }
};
