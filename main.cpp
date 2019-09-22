#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include <cstring>
#include <unordered_set>
#include <map>

using namespace std;

vector<vector<int>> p;

bool isSubsequence(string s, string word) {
    int m = word.size(), cur = m;
    for(int i = m-1; i >= 0; i--) {
            if (p[cur][word[i]-'a'] == -1) return false;
            cur = p[cur][word[i]-'a'];
    }
    return true;
}

int numMatchingSubseq(string S, vector<string>& words) {
    int res = 0;
    p = vector<vector<int>>(S.size() + 1, vector<int>(26, -1));
    for(int i = 1; i <= S.size(); i++)
            for(char c = 'a'; c <= 'z'; c++)
                    if (S[i-1] == c) p[i][c-'a'] = i-1;
                    else p[i][c-'a'] = p[i-1][c-'a'];

    cout<<p[5][3]<<endl;
    cout<<p[3][2]<<endl;
    cout<<p[2][0];
    for(string word: words)
            if (isSubsequence(S, word)) {
                     res++;
                    cout<<word<<endl;
            }
    return res;
}

int main() {
    vector<string> words = { "acd", "a", "b", "de" };
    cout<<numMatchingSubseq("abcde", words);
    return 0;
}