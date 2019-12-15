class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
	unordered_map<string, int> pos;
	int i = -1;
	int res = words.size();
	for(string w: words) {
		pos[w] = ++i;
		if (w == word1 && pos.count(word2) != 0) res = min(res, i - pos[word2]);
		if (w == word2 && pos.count(word1) != 0) res = min(res, i - pos[word1]); 
	}        
	return res;
    }
};
