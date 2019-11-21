class Solution {
public:
    bool ok(string s, string t) {
	int n = s.size();
	int m = t.size();
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (s[i] == t[j]) { i++; j++; }
		else i++;
	}
	return j == m;
    }
	
    string findLongestWord(string s, vector<string>& d) {
	string res = "";
	sort(d.begin(), d.end());
	for(string t: d) 
		if (ok(s, t))
			if (t.size() > res.size()) res = t;	 
	return res;       
    }
};
