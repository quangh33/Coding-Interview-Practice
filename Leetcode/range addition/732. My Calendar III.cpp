//
// Created by Hoang, Quang on 2019-09-25.
//

class MyCalendarThree {
public:
    map<int, int> s;

    MyCalendarThree() {

    }

    int book(int start, int end) {
        s[start]++;
        s[end]--;
        int count = 0;
        int res = 0;
        for(auto pair: s) {
            count += pair.second;
            res = max(res, count);
        }
        return res;
    }
};