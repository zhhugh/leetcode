//
// Created by zhouhan on 2021/3/6.
//
#include "../common.h"
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        for(int i = 0; i < n; i++){
            while(!stk.empty() && nums[i] > nums[stk.top()]){
                ans[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        for(int i = 0; i < n; i++){
            while(!stk.empty() && nums[i] > nums[stk.top()]){
                if(ans[stk.top()] == -1){
                    ans[stk.top()] = nums[i];
                }
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};


class Solution2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        for(int i = 0; i < 2 * n - 1; i++){
            while(!stk.empty() && nums[i % n] > nums[stk.top()]){
                ans[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ans;
    }
};