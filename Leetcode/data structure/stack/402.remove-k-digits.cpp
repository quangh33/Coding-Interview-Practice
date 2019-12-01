class Solution {
public:
    string removeKdigits(string num, int k) {
	stack<char> s;
	for(char c: num) {
		while (!s.empty() && k > 0 && s.top() > c) {
			s.pop();
			k--;
		}
		s.push(c);
	}        

	for(int i = 1; i <= k; i++) s.pop();
	string res = "";
	while (!s.empty()) {
		res = s.top() + res;
		s.pop();
	};

	while (res[0] == '0') res.erase(res.begin());
	if (res.size() == 0) return "0";
	return res;
    }
};
