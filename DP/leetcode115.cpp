//
// Created by zhouhan on 2021/3/17.
//
#include "../common.h"
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.empty() || t.empty()){
            return 0;
        }
        int n = s.size();
        int m = t.size();
        long long dp[n][m];
        fill(dp[0], dp[n], 0);
        if(s[0] == t[0]){
            dp[0][0] = 1;
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i][j] = dp[i - 1][j];
                if(s[i] == t[j]){
                    dp[i][j] += j > 0 ? dp[i - 1][j - 1] : 1;
                }
            }
        }
        return (int)dp[n - 1][m - 1];
    }
};


class Solution2 {
public:
    int numDistinct(string s, string t) {
        if(s.empty() || t.empty()){
            return 0;
        }
        int n = s.size();
        int m = t.size();
        long long dp[2][m];
        fill(dp[0], dp[2], 0);
        if(s[0] == t[0]){
            dp[0][0] = 1;
        }
        int pre = 0;
        int cur = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[cur][j] = dp[pre][j];
                if(s[i] == t[j]){
                    dp[cur][j] += j > 0 ? dp[pre][j - 1] : 1;
                }
            }
            swap(cur, pre);
        }
        return (int)dp[pre][m - 1];
    }
};