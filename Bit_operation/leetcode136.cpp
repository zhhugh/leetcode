//
// Created by zhouhan on 2021/1/24.
//

// 只出现一次的的数字
#include "../common.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int eor = 0;
        for(auto i: nums){
            eor ^= i;
        }
        return eor;
    }
};