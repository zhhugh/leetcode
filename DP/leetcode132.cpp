//
// Created by zhouhan on 2021/3/8.
//
#include "../common.h"
class Solution {
public:
    vector<vector<int>> f;
    int minCut(string s) {
        int n = s.size();
        f = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        int dp[n];
        fill(dp, dp + n, INT_MAX);
        for(int left = n - 1; left >= 0; left--){
            for(int right = left + 1; right < n; right++){
                f[left][right] = (s[left] == s[right]) && f[left + 1][right - 1];
            }
        }

        for(int i = 0; i < n; i++){// [0..i]
            if(f[0][i]){
                dp[i] = 0;
            }else {
                for (int j = i; j > 0; j--) { // [j...i]回文
                    if (f[j][i]) {
                        dp[i] = min(dp[j - 1] + 1, dp[i]);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};