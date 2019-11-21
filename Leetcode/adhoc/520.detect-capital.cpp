class Solution {
public:
    bool detectCapitalUse(string word) {
	int upper = 0, lower = 0, n = word.size();
	for(char c: word) {
		if (islower(c)) lower++;
		else upper++;
	}        
	if (lower == n || upper == n) return true;
	if (lower == n-1 && isupper(word[0])) return true;
	return false;
    }
};
