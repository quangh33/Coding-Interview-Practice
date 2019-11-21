//
// Created by Hoang, Quang on 2019-09-25.
//

class MyCalendar {
public:
    map<int, int> booked;

    MyCalendar() {

    }

    bool book(int start, int end) {
        if (booked.size() != 0) {
            auto i = booked.lower_bound(end);
            if (i != booked.begin()) {
                i--;
                if (i->second > start) return false;
            }
        }
        booked[start] = end;
        return true;
    }
};
