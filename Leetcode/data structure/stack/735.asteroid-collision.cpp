class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
	int n = a.size();
	stack<int> s;
	s.push(a[0]);
	for(int i = 1; i < n; i++) {
		int blow = false;
		int coming = a[i];
		while (!s.empty() && s.top() > 0 && a[i] < 0) {
			int last = s.top();
			if (abs(last) == abs(coming)) {
				s.pop();
				blow = true;
				break;
			} else if (abs(last) < abs(coming)) {
				s.pop();
			} else {
				blow = true;
				break;
			}
		}
		if (!blow) s.push(a[i]);
	}
	vector<int> res;
	while (!s.empty()) {
		int top = s.top();
		s.pop();	
		res.push_back(top);
	}
	reverse(res.begin(), res.end());
	return res;
    }
};
