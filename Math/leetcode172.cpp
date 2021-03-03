//
// Created by zhouhan on 2021/3/3.
//

#include "../common.h"
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n > 0){
            cnt += n / 5;
            n = n / 5;
        }
        return cnt;
    }
};