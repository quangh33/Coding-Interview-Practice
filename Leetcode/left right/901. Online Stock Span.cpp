//
// Created by Hoang, Quang on 2019-09-24.
//

// https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    vector<int> a;
    vector<int> left;
    int n;
    StockSpanner() {
        n = -1;
    }

    int next(int price) {
        n++;
        a.push_back(price);
        left.push_back(-1);

        if (n == 0) {
            left[n] = -1;
            return 1;
        }

        if (a[n-1] > a[n]) {
            left[n] = n-1;
            return 1;
        } else {
            int j = n-1;
            while (j != -1 && a[j] <= a[n]) j = left[j];
            left[n] = j;
            return (n-left[n]);
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */