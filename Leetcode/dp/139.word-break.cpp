class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
	unordered_set<string> dic;
	for(string s: wordDict) dic.insert(s);
	int n = s.size();
	if (n == 0) return true;
	bool fx[n+1];
	fx[0] = true;
	for(int i = 1; i <= n; i++) {
		fx[i] = false;
		for(int j = 0; j < i; j++) {
			if (dic.count(s.substr(j, i-j)) != 0)
				fx[i] = fx[i] | fx[j];
		}
	}        
	return fx[n];
    }
};
