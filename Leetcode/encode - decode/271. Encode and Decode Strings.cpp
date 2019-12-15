//
// Created by Hoang, Quang on 2019-12-15.
//

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encodeString(string s) {
        string ans = "";
        for (char c: s) {
            ans = ans + to_string(int(c)) + ".";
        }
        return ans;
    }

    string decodeString(string s) {
        string ans = "";
        int cur = 0;
        for (char c: s) {
            if (c != '.') {
                cur = (cur * 10) + (c - '0');
            } else {
                ans += char(cur);
                cur = 0;
            }
        }
        return ans;
    }

    string encode(vector <string> &strs) {
        string res = "";
        for (string s: strs) {
            res = res + encodeString(s) + "#";
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector <string> decode(string s) {
        vector <string> res;
        string current = "";
        for (char c: s) {
            if (c == '#') {
                res.push_back(decodeString(current));
                current = "";
            } else current += c;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));