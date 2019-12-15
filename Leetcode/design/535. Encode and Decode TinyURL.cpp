//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    unordered_map <string, string> dic;
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string getRand() {
        srand(1);
        string res = "";
        for (int i = 1; i <= 6; i++)
            res = res + alphabet[rand() % 62];

        return res;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = getRand();
        while (dic.find(key) != dic.end()) {
            key = getRand();
        }
        dic[key] = longUrl;
        return "http://tinyurl.com/" + key;
    }


    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string domain = "http://tinyurl.com/";
        string key = shortUrl.substr(domain.size(), shortUrl.size() - domain.size());
        return dic[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));