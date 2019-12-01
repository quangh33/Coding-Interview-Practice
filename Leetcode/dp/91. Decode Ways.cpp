class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int fx[n];
        fx[0] = s[0] == '0' ? 0 : 1;
        for(int i = 1; i < n; i++) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') fx[i] = (i == 1 ? 1 : fx[i-2]);
                else return 0;
            } else {
                fx[i] = fx[i-1];
                string a = string() + s[i-1] + s[i];
                if (10 < stoi(a) && stoi(a) <= 26) fx[i] = fx[i] + (i == 1 ? 1 : fx[i-2]);   
            }
        }
        return fx[n-1];
    }
};