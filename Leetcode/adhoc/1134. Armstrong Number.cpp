//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    bool isArmstrong(int N) {
        string s = to_string(N);
        int k = s.size();
        int m = 0;
        int temp = N;
        while (N) {
            int d = N % 10;
            N /= 10;
            int pow = 1;
            for (int i = 1; i <= k; i++)
                pow *= d;
            m += pow;
            if (m > temp) return false;
        }

        return m == temp;
    }
};