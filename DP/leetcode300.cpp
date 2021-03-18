//
// Created by zhouhan on 2021/3/4.
//
// 最长上升子序列
#include "../common.h"

class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxVal = 1;
        for(int i = 1; i < n; i++){
            // [0...j - 1] 找到最后一个比nums
            for(int j = 0; j <= i - 1; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};

// f[i] 表示长度为i的的最长上升子串结尾的最小值

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int n = nums.size();
        vector<int> dp{nums[0]};
        for(int i = 1; i < n; i++){
            int num = nums[i];
            if(num > dp.back()){
                dp.push_back(num);
            }else{
                auto it = lower_bound(dp.begin(), dp.end(), num);
                *it = num;
            }
        }
        return dp.size();
    }
};