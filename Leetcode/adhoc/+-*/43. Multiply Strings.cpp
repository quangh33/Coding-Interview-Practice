//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:

    string mul(string a, int x, int zero) {
        string res = "";
        int carry = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            int m = (a[i] - '0') * x + carry;
            res = to_string(m % 10) + res;
            carry = m / 10;
        }
        if (carry != 0) res = to_string(carry) + res;
        for (int i = 1; i <= zero; i++)
            res = res + "0";

        return res;
    }

    string plus(string a, string b) {
        string res = "";
        int carry = 0;
        if (a.size() > b.size()) swap(a, b);
        while (a.size() < b.size()) a = "0" + a;
        for (int i = a.size() - 1; i >= 0; i--) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            res = to_string(sum % 10) + res;
            carry = sum / 10;
        }
        if (carry != 0) res = "1" + res;
        return res;
    }

    string multiply(string a, string b) {
        int n = a.size();
        int m = b.size();
        string res = "0";
        int zero = -1;
        for (int i = m - 1; i >= 0; i--) {
            int d = b[i] - '0';
            zero++;
            res = plus(res, mul(a, d, zero));
        }
        while (res.size() > 1 && res[0] == '0') res.erase(res.begin());
        return res;
    }
};