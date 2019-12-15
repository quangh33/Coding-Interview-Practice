//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    string convert(int n, string one, string five, string ten) {
        switch (n) {
            case 1:
                return one;
            case 2:
                return one + one;
            case 3:
                return one + one + one;
            case 4:
                return one + five;
            case 5:
                return five;
            case 6:
                return five + one;
            case 7:
                return five + one + one;
            case 8:
                return five + one + one + one;
            case 9:
                return one + ten;
        }
        return "";
    }

    string intToRoman(int num) {
        int d = num % 10;
        num = num / 10;
        int c = num % 10;
        num = num / 10;
        int b = num % 10;
        num = num / 10;
        int a = num % 10;

        string res = "";
        for (int i = 1; i <= a; i++) res = res + "M";
        res += convert(b, "C", "D", "M");
        res += convert(c, "X", "L", "C");
        res += convert(d, "I", "V", "X");

        return res;
    }
};
