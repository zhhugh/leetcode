//
// Created by zhouhan on 2021/3/8.
//
#include "../common.h"
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1){
            return 1;
        }
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = arr[1] != arr[0] ? 2 : 1;
        int maxLen = dp[1];
        for(int i = 2; i < n; i++){
            bool valid = arr[i - 1] > arr[i - 2] ? arr[i] < arr[i - 1] : arr[i] > arr[i - 1];
            dp[i] = valid ? dp[i - 1] + 1 : (arr[i] == arr[i - 1] ? 1 : 2);
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};