//
// Created by zhouhan on 2021/3/24.
//
#include "../common.h"
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int min1[n];
        int min2[n];
        min1[0] = nums[0];
        min2[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++){
            min1[i] = min(nums[i], min1[i - 1]);
        }
        for(int i = 1; i < n - 1; i++){
            if(nums[i] > min1[i - 1]){
                for(int j = i + 1; j < n; j++){
                    if(nums[j] < nums[i] && nums[j] > min1[i - 1]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int k = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < k){
                return true;
            }
            while(!stk.empty() && nums[i] > stk.top()){
                k = max(k, stk.top());
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};