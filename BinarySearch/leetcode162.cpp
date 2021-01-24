//
// Created by zhouhan on 2021/1/24.
//

// leetcode 162 寻找峰值
// 先判断nums[0] > nums[1], 如果成立， 则返回结果
// 判断nums[n - 1] > nums[n - 2], 如果成立， 则返回结果
// 以上两点均不成立， 则说明[1, n - 1]中必有峰值
// 如果nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1], 则返回答案
// 排除上面的情况， nums[mid] < nums[mid - 1], 则[l, mid- 1]中必然有答案
// 排除上面的情况， nums[mid] > nums[mid + 1], 则[mid + 1, r]中必有答案
// 当区间只剩下一个数的时候， 这个数必然是答案


#include "../common.h"
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // 保证数组必须有两个元素
        if(n <= 1) return 0;

        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n - 1] > nums[n - 2]){
            return n - 1;
        }
        int l = 1, r = n - 2;
        while(l < r){
            int mid = (l + r) >> 1;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
                return mid;
            }else if(nums[mid] < nums[mid - 1]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};