//
// Created by zhouhan on 2021/1/27.
//

// leetcdoe 739 每日温度

#include "../common.h"
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk; // 单调栈， 底->顶 大->小
        int n = T.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            // 将栈中小于T[i]的元素出栈，生成记录
            while(!stk.empty() && T[stk.top()] < T[i]){
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};