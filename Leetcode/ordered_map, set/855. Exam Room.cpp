//
// Created by Hoang, Quang on 2019-12-01.
//

class ExamRoom {
public:
    set<int> students;
    int n;

    ExamRoom(int N) {
        n = N;
    }

    int seat() {
        if (students.size() == 0) {
            students.insert(0);
            return 0;
        }

        int pos = 0;
        int maxDis = *students.begin();
        int prev = -1;
        for (auto s: students) {
            if (prev == -1) {
                prev = s;
                continue;
            }
            if ((s - prev) / 2 > maxDis) {
                maxDis = (s - prev) / 2;
                pos = prev + (s - prev) / 2;
            }
            prev = s;
        }

        int last = *(--students.end());
        if (n - 1 - last > maxDis) {
            maxDis = n - 1 - last;
            pos = n - 1;
        }

        students.insert(pos);
        return pos;
    }

    void leave(int p) {
        students.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */