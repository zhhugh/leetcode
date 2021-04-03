//
// Created by zhouhan on 2021/4/3.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int dp[m + 1][n + 1];
        fill(dp[0], dp[m + 1], 0);
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i - 1] == text2[j - 1]){// 和最后一个匹配
                    dp[i][j] =  dp[i - 1][j - 1] + 1;
                }else{// 不和最后一个匹配
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};