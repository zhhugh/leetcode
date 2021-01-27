//
// Created by zhouhan on 2021/1/27.
//

#include "../common.h"
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int length = heights.size();
        int ans = 0;
        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int idx = stk.top();
                int curHeight = heights[idx];
                stk.pop();
                while(!stk.empty() && heights[stk.top()] == curHeight){
                    stk.pop();
                }
                int left = stk.empty() ? 0 : stk.top() + 1;
                ans = max((i - left) * curHeight, ans);
            }

            stk.push(i);
        }
        while (!stk.empty()) {
            int idx = stk.top();
            int curHeight = heights[idx];
            stk.pop();
            while(!stk.empty() && heights[stk.top()] == curHeight){
                stk.pop();
            }
            int left = stk.empty() ? 0 : stk.top() + 1;
            ans = max((length - left) * curHeight, ans);
        }
        return ans;
    }
};