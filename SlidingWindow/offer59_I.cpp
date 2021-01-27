//
// Created by zhouhan on 2021/1/26.
//
// 滑动窗口的最大值（最小值）
#include "../common.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> qmax; // 双端队列维持的性质：从左到右为严格递减
        vector<int> ans;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            // 进数
            while(!qmax.empty() && nums[qmax.back()] <= nums[i]){
                qmax.pop_back();
            }
            qmax.push_back(i);
            // 找过期下标, 如果下标过期则弹出队列， 如果没有形成大小为k的窗口则不弹
            // 因为窗口没有出数， 也就没有下标过期
            if(i - k == qmax.front()){
                qmax.pop_front();
            }
            // 如果形成了窗口，就记录答
            if(i >= k - 1){
                ans.push_back(nums[qmax.front()]);
            }
        }
        return ans;
    }
};

