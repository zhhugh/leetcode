//
// Created by zhouhan on 2021/2/21.
//
#include "../common.h"
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size();
    int m = multipliers.size();
    int maxval = INT_MIN;
    int dp[1001][1001];
    for(int k = 1; k <= m; k ++){
        for(int i = 0; i <= k; i++){
            if(i == 0){
                dp[i][k - i] = dp[i][k - i - 1] + multipliers[k - 1] * nums[n - k + i];
            }else if(i == k){// k - i == 0，此分支填写二维表的第一列
                dp[i][k - i] = dp[i - 1][k - i] + multipliers[k - 1] * nums[i - 1];
            }else{
                dp[i][k - i] = max(
                        dp[i - 1][k - i] + multipliers[k - 1] * nums[i - 1],
                        dp[i][k - i - 1] + multipliers[k - 1] * nums[n - k + i]
                );
            }
            if(k == m){
                maxval = max(dp[i][k - i], maxval);
            }
        }
    }
    return maxval;
    }
};