//
// Created by zhouhan on 2021/2/1.
//

class Solution {
public:
    double myPow(double x, int n) {
        bool neg = n < 0;
        long long m = n;
        if(neg){
            m = -m;
        }
        double tmp = x;
        double res = 1;
        while(m){
            if(m & 1){
                res *= tmp;
            }
            m >>= 1;
            tmp *= tmp;
        }
        if(neg){
            return 1 / res;
        }else{
            return res;
        }
    }
};