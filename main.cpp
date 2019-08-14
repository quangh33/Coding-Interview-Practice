#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <queue>
#include <array>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> children[5001];

void convert(string S, vector<string> &a) {
    int i = 0;
    int n = S.length();
    while (i < n) {
        if (S[i] == '+' || S[i] == '-' || S[i] == ')' || S[i] == '(') {
            a.push_back(string(1, S[i]));
            i++;
        } else if (S[i] != ' ') {
            int j = i;
            string num = string(1, S[i]);
            while (j + 1 < n && isdigit(S[j + 1])) {
                j++;
                num += S[j];
            }
            a.push_back(num);
            i = j + 1;
        }
    }
}

int calculate(string s) {
    string S = "";
    for (char c: s) if (c != ' ') S += c;
    int n = S.length();
    if (n == 0) return 0;

    vector<int> value;
    vector<int> sign;
    vector<string> a;

    convert(S, a);

    int count = 0;
    stack<pair<char, int>> st;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == "(") {
            if (i == 0 || a[i - 1] == "+") st.push(make_pair('(', 1));
            else {
                st.push(make_pair('(', -1));
                count++;
            }
        } else if (a[i] == ")") {
            if (st.top().second == -1) count--;
            st.pop();
        } else if (a[i] != "+" && a[i] != "-") {
            int currentSign = 1;
            if (i > 0 && a[i - 1] == "-") currentSign = -1;
            if (count % 2 == 1) currentSign = -currentSign;
            value.push_back(stoi(a[i]));
            sign.push_back(currentSign);
        }
    }

    int res = 0;
    for (int i = 0; i < value.size(); i++) {
        res += value[i] * sign[i];
        // cout<<value[i] * sign[i]<<endl;
    }
    return res;
}

int n;

long long pow(int n) {
    if (n == 0) return 1;
    if (n == 1) return 10;
    long long x = pow(n / 2);
    if (n % 2 == 0) return x * x;
    return x * x * 10;
}

long long cal(int i, int j, string num) {
    if (i == num.length()) {
        if (j > 0) return 1e9;
        else return 0;
    }
    return min(cal(i + 1, j, num), cal(i + 1, j - 1, num) + (num[i] - '0') * pow(j-1));
}

string removeKdigits(string num, int k) {
    if (k == num.size()) {
        return "0";
    }
    stack<char> stk;
    for (char c : num) {
        while (k && !stk.empty() && stk.top() > c) {
            stk.pop();
            k--;
        }
        stk.push(c);
    }
    while (k) {
        stk.pop();
        k--;
    }
    string ans;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    while (ans.size() > 1 && ans.back() == '0') {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main() {
    cout << removeKdigits("1432129", 3);
    return 0;
}