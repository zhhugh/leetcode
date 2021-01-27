//
// Created by zhouhan on 2021/1/24.
//

// leetcode 260 只出现一次的数字III
#include "../common.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int eor  = 0;
        for(auto i : nums){
            eor ^= i;
        }
        // eor = a ^ b
        // 找到最后一个1
        int lastOne = eor &((~eor) + 1);
        int firstOne = 0;
        // 根据该位是否有1， 划分为两类， a 和 b 分别在不同的类中
        for(auto i: nums){
            if(lastOne & i){
                firstOne ^= i;
            }
        }
        return vector<int> {firstOne, eor ^ firstOne};
    }
};