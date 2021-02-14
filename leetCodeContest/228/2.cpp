//
// Created by zhouhan on 2021/2/14.
//
#include "../../common.h"
class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int cnt = 1;
        long long ans = 0;
        int cur = 1;
        int mod = 1e9 + 7;
        while(cur <= n){
            if(s[cur] == s[cur - 1]){
                cnt ++;
            }else{
                ans += ((1 + cnt) * cnt) / 2 % mod;
                cnt = 1;
            }
            cur ++;
        }
        return (int)(ans % mod);
    }
};