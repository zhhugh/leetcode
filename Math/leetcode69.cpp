//
// Created by zhouhan on 2021/3/1.
// 牛顿迭代法计算方程的根
#include "../common.h"

class Solution {
public:
    double a;
    int mySqrt(int x) {
        a = x;
        if(x == 0){
            return x;
        }
        return (int)sqrt(x);
    }

    double sqrt(double x){
        double res = (x + a / x) / 2;
        if(abs(res - x) < 1e-7){ // 解的变化不大
            return x;
        }else{
            return sqrt(res);
        }
    }
};