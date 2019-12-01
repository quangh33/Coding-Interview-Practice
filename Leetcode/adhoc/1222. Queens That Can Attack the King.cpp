class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        bool isQueen[64][64];
        memset(isQueen, false, sizeof(isQueen));
        for(auto q: queens)
            isQueen[q[0]][q[1]] = true;
       
        vector<vector<int>> res;
        for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++) 
                if (i | j) {
                    int u = king[0];
                    int v = king[1];
                    while (true) {
                        u = u + i;
                        v = v + j;
                        if (u >= 0 && u <= 63 && v >= 0 && v <= 63) {
                            if (isQueen[u][v]) {
                                res.push_back({ u, v });
                                break;
                            }
                        } else break;
                    }
                }
        return res;
    }
};