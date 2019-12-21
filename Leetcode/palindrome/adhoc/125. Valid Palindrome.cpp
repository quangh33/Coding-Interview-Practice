//
// Created by Hoang, Quang on 2019-08-24.
//

// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            if (!isalnum(s[i])) i++;
            else if (!isalnum(s[j])) j--;
            else {
                if (tolower(s[i]) != tolower(s[j])) return false;
                i++;
                j--;
            }
        }
        return true;
    }
};

