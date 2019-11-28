class Solution {
public:
    int next(int x) {
        int res = 0;
        while (x != 0) {
            int i = x % 10;
            res += i * i;
            x = x/ 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (slow != 1 && fast != 1 && next(fast) != 1) {
            slow = next(slow);
            fast = next(next(fast));
            if (slow == fast) return false;
        }
        return true;
    }
};