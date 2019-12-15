//
// Created by Hoang, Quang on 2019-12-15.
//

class Logger {
public:
    /** Initialize your data structure here. */

    unordered_map<string, int> time;

    Logger() {
        time.clear();
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (time.count(message) == 0 || timestamp - time[message] >= 10) {
            time[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
