//
// Created by zhouhan on 2021/1/27.
//

// leetcdoe 739 每日温度

#include "../common.h"
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk; //
        int n = T.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            while(!stk.empty() && T[stk.top()] < T[i]){
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            res[stk.top()] = 0;
            stk.pop();
        }
        return res;
    }
};