//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size()) return addBinary(b, a);
        while (a.size() < b.size()) a = "0" + a;
        int carry = 0;
        string res = "";
        for (int i = a.size() - 1; i >= 0; i--) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        if (carry != 0) res = "1" + res;
        return res;
    }
};