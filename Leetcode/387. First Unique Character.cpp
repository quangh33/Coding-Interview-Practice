//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/first-unique-character-in-a-string/

#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        int count[30];
        memset(count, 0, sizeof(count));
        for(int i = 0; i < n; i++) count[int(s[i]) - int('a')]++;
        for(int i = 0; i < n; i++)  {
            if (count[int(s[i]) - 'a'] == 1) return i;
        }
        return -1;
    }
};