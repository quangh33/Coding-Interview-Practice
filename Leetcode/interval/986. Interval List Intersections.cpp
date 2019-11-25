//
// Created by Hoang, Quang on 2019-11-22.
//

class Solution {
public:

    vector<int> intersection(vector<int> a, vector<int> b) {
        if (a[1] < b[0]) return {};
        if (b[1] < a[0]) return {};
        if (a[0] >= b[0] && a[0] <= b[1]) return {a[0], min(a[1], b[1])};
        return {b[0], min(b[1], a[1])};
    }

    vector <vector<int>> intervalIntersection(vector <vector<int>> &A, vector <vector<int>> &B) {
        int i = 0;
        int j = 0;
        vector <vector<int>> res;

        while (i < A.size() && j < B.size()) {
            vector<int> x = intersection(A[i], B[j]);
            if (x.size() > 0) res.push_back(x);
            if (A[i][1] > B[j][1]) j++;
            else i++;
        }

        return res;
    }
};
