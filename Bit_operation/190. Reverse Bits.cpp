//
// Created by zhouhan on 2021/3/30.
//
#include <iostream>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int shift = 1;
        for(int i = 0; i < 32; i++){
            res =  res * 2 + (n & 1);
            n = n >> 1;
        }
        return res;
    }
};
