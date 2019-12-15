//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    bool isValidDigit(int i) {
        return i == 0 || i == 1 || i == 6 || i == 8 || i == 9;
    }

    bool confusingNumber(int N) {
        unordered_map<int, int> m;
        m[0] = 0;
        m[1] = 1;
        m[6] = 9;
        m[8] = 8;
        m[9] = 6;
        int M = 0;
        int temp = N;
        while (N != 0) {
            int d = N % 10;
            if (!isValidDigit(d)) return false;
            M = M * 10 + m[d];
            N = N / 10;
        }
        return M != temp;
    }
};