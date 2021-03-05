//
// Created by zhouhan on 2021/3/5.
//
#include "../common.h"
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        int a = 0;
        int b = 0;
        int maxVal = 0;
        for(auto num: nums){
            maxVal = max(a, b + num);
            b = a;
            a = maxVal;
        }
        return maxVal;
    }
};