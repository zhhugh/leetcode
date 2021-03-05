//
// Created by zhouhan on 2021/3/4.
//
#include "../common.h"
//[2 3] [5 4] [6 4] [6 7]
// 如果env[i] > [env[pre] ... env[i - 1] pre = i
// 其中{env[pre] ... env[i-1] 必须大于env[pre - 1]
class Solution {
public:
    static bool cmp(vector<int> e1, vector<int> e2){
        return (e1[0] < e2[0]) || (e1[0] == e2[0] && e1[1] > e2[1]);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()){
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), cmp);
        int n = envelopes.size();
        vector<int> dp(n, 1);
        int maxVal = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i - 1; j++){
                if(envelopes[i][1] > envelopes[j][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxVal = max(dp[i], maxVal);
        }
        return maxVal;
    }
};


// 状态定义

class Solution2 {
public:
    static bool cmp(vector<int> e1, vector<int> e2){
        return (e1[0] < e2[0]) || (e1[0] == e2[0] && e1[1] > e2[1]);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()){
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), cmp);
        int n = envelopes.size();
        vector<int> dp{envelopes[0][1]};
        for(int i = 1; i < n; i++){
            int num = envelopes[i][1];
            if( num > dp.back()){
                dp.push_back(num);
            }else{
                auto it = lower_bound(dp.begin(), dp.end(), num);
                *it = num;
            }
        }
        return dp.size();
    }
};