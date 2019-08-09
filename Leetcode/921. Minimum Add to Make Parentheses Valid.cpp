//
// Created by Hoang, Quang on 2019-08-09.
//
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#include <string>
#include <stack>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(s[i]);
            else {
                if (!st.empty() && st.top() == '(') st.pop();
                else st.push(s[i]);
            }
        }
        return st.size();
    }
};