//
// Created by Hoang, Quang on 2019-08-23.
//

// https://leetcode.com/problems/binary-watch/

class Solution {
public:
    vector<bool> pickedHour, pickedMin;
    vector<string> res;
    int hour, min;
    vector<int> hours, minutes;
    int x[4] = { 1, 2, 4, 8 };
    int y[6] = { 1, 2, 4, 8, 16, 32 };

    void buildHour(int i, int from, int count) {
        if (i == count) {
            hours.push_back(hour);
            return;
        }
        for(int j = from; j < 4; j++) {
            if (!pickedHour[j]) {
                pickedHour[j] = true;
                hour+=x[j];
                buildHour(i+1, j, count);
                pickedHour[j] = false;
                hour-=x[j];
            }
        }
    }

    void buildMinute(int i, int from, int count) {
        if (i == count) {
            minutes.push_back(min);
            return;
        }
        for(int j = from; j < 6; j++) {
            if (!pickedMin[j]) {
                pickedMin[j] = true;
                min+=y[j];
                buildMinute(i+1, j, count);
                pickedMin[j] = false;
                min-=y[j];
            }
        }
    }

    vector<string> readBinaryWatch(int num) {
        for(int i = 0; i <= num; i++) {
            pickedHour = vector<bool>(4, false);
            pickedMin = vector<bool>(6, false);
            hour = 0;
            min = 0;
            hours = vector<int>(0);
            minutes = vector<int>(0);
            buildHour(0, 0, i);
            buildMinute(0, 0, num - i);
            for(int h: hours)
                for(int m: minutes) {
                    if (h > 11 || m > 59) continue;
                    string minute = m < 10 ? "0" + to_string(m) : to_string(m);
                    string time = to_string(h) + ":" + minute;
                    res.push_back(time);
                }
        }
        return res;
    }
};

