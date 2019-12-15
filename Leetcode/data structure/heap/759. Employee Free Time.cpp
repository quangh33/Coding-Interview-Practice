//
// Created by Hoang, Quang on 2019-12-15.
//

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    typedef pair<int, pair<int, int>> ii;

    vector<Interval *> employeeFreeTime(vector <vector<Interval *>> s) {
        vector < Interval * > a, b, res;
        priority_queue <ii, vector<ii>, greater<ii>> q;
        for (int i = 0; i < s.size(); i++)
            if (s[i].size() > 0)
                q.push(ii(s[i][0]->start, make_pair(i, 0)));

        while (!q.empty()) {
            int minRow = q.top().second.first;
            int minCol = q.top().second.second;
            a.push_back(s[minRow][minCol]);
            q.pop();
            if (minCol + 1 < s[minRow].size())
                q.push(ii(s[minRow][minCol + 1]->start, make_pair(minRow, minCol + 1)));
        }

        int i = 0;
        int n = a.size();
        while (i < n) {
            int j = i;
            int end = a[i]->end;
            while (j + 1 < n && a[j + 1]->start <= end) {
                j++;
                end = max(end, a[j]->end);
            }
            Interval *merged = new Interval(a[i]->start, end);
            b.push_back(merged);
            i = j + 1;
        }

        for (Interval *i: b) cout << i->start << " " << i->end << endl;

        for (int i = 0; i < b.size() - 1; i++) {
            Interval *free = new Interval(b[i]->end, b[i + 1]->start);
            res.push_back(free);
        }

        return res;
    }
};