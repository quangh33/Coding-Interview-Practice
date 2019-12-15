//
// Created by Hoang, Quang on 2019-09-25.
//

class MyCalendarTwo {
public:

    map<int, int> s;

    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        s[start]++;
        s[end]--;
        int count = 0;
        for(auto pair: s) {
            count += pair.second;
            if (count > 2) {
                s[start]--;
                s[end]++;
                return false;
            }
        }
        return true;
    }
};