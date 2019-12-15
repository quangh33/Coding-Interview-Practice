//
// Created by Hoang, Quang on 2019-12-14.
//

class Solution {
public:
    void sortColors(vector<int> &a) {
        int n = a.size();
        int zero = 0;
        int i = 0;
        int two = n;
        while (i < two) {
            if (a[i] == 0) {
                swap(a[i], a[zero]);
                i++;
                zero++;
            } else if (a[i] == 1) i++;
            else {
                two--;
                swap(a[i], a[two]);
            }
        }
    }
};