//
// Created by zhouhan on 2021/3/3.
//
#include "../common.h"

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        int tmp = num;
        while(tmp != 0){
            if((tmp & 1) == 1){
                dp[num]++;
            }
            tmp >>= 1;
        }
        int preLastNum = ~(num - 1) & num;
        for(int i = num - 1; i > 0; i--){
               int numOfOnes = log(preLastNum);
               dp[i] = dp[i - 1] - 1 + numOfOnes;
               preLastNum = ~(i - 1) & i;
        }
        return dp;
    }
};

class Solution2 {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for(int i = 1; i <= num; i++){
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};