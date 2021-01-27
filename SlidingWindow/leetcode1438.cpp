//
// Created by zhouhan on 2021/1/26.
//

// 1438. 绝对差不超过限制的最长连续子数组

#include "../common.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int L, R = 0;
        deque<int> qmax;
        deque<int> qmin;
        int res = 0;
        // 枚举左边界， 如果[L...R]不满足条件， 则[L...R']也不满足条件（R' > R)
        // 如果 [L...R]满足条件， 则其子区间也满足条件
        for(L = 0; L < n; L++){
            // R 向右拓展， 拓展到第一个不满足条件的位置
            while(R < n){
                while(!qmax.empty() && nums[qmax.back()] <= nums[R]){
                    qmax.pop_back();
                }
                qmax.push_back(R);
                while(!qmin.empty() && nums[qmin.back()] >= nums[R]){
                    qmin.pop_back();
                }
                qmin.push_back(R);
                // R 到达第一个不合法的位置
                if(nums[qmax.front()] - nums[qmin.front()] > limit){
                    break;
                }
                // R 向右边拓展
                R++;
            }
            // R为第一个不满足条件的右边界
            res = max(res, R - L);
            // 判断下标是否过期
            if(L == qmax.front()){
                qmax.pop_front();
            }
            if(L == qmin.front()){
                qmin.pop_front();
            }
        }
        return res;
    }
};