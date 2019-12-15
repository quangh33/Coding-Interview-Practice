// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
	int low = 1, high = n, res;
	while (low <= high) {
		int mid = low + ((high - low) / 2);
		if (isBadVersion(mid)) {
			res = mid;
			high = mid - 1;
		} else low = mid + 1;
	}        
	return res;
    }
};
