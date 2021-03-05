//
// Created by zhouhan on 2021/3/5.
//
#include "../common.h"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int maxVal = nums[0];
        for(int i = 1; i < n; i++){
            dp[i] = dp[i - 1] < 0 ? nums[i] : dp[i - 1] + nums[i];
            maxVal = max(dp[i], maxVal);
        }
        return maxVal;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int maxVal = nums[0];
        for(auto num: nums){
            pre = max(num + pre, num);
            maxVal = max(maxVal, pre);
        }
        return maxVal;
    }
};