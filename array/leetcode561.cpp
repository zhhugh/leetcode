//
// Created by zhouhan on 2021/2/16.
//
#include "../common.h"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < n; i+=2){
            ans += nums[i];
        }
        return ans;
    }
};