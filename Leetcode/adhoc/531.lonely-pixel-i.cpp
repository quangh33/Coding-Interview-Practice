class Solution {
public:
    int findLonelyPixel(vector <vector<char>> &a) {
        int n = a.size();
        if (n == 0) return 0;
        int m = a[0].size();
        if (m == 0) return 0;
        int row[n], col[m];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) count += (a[i][j] == 'B');
            row[i] = count;
        }

        for (int j = 0; j < m; j++) {
            int count = 0;
            for (int i = 0; i < n; i++) count += (a[i][j] == 'B');
            col[j] = count;
        }

        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == 'B') {
                    if (col[j] == 1 && row[i] == 1) res++;
                }

        return res;
    }
};
