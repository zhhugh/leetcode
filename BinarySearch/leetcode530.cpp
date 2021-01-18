//
// Created by zhouhan on 2021/1/18.
//
// leetcode 540 有序数组中的单一元素
// https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
// 二分搜索通常是针对有序数组
// 精髓在于， 二分出来的那个索引可以将区间划分为两部分， 一部分是解所在的区间
// 另一部分是非解区间， 这样将解区间不断缩小， 直至为一个数或退出

#include "../common.h"
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[len - 1] != nums[len - 2]){
            return nums[len - 1];
        }
        int l = 2, r = len - 3;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]){
                return nums[mid];
            }else if(nums[mid] == nums[mid + 1]){
                if(mid % 2){
                    r = mid - 1;
                }else{
                    l = mid + 2;
                }
            }else if(nums[mid] == nums[mid - 1]){
                if((mid - 1) % 2){
                    r = mid - 2;
                }else{
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};

// 官方解法 默认一定能够找到
// 细节： 如果让 l < r, 那么mid 不可能是 0 或者 len - 1，
// 那么在不需要判断mid - 1 和 mid + 1 是不是越界了
// 最后退出的时候是 l == r， 区间中只剩下一个数， 那一定是答案（假定一定能找到）
// 位运算判断奇数和偶数， 除以2的时候是移一位不是两位

class Solution2 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            cout << mid << endl;
            if(nums[mid]  == nums[mid + 1]){
                if(mid & 1){
                    r = mid - 1;
                }else{
                    l = mid + 2;
                }
            }else if (nums[mid] == nums[mid - 1]){
                if(!(mid & 1)){
                    r = mid - 2;
                }else{
                    l = mid + 1;
                }
            }else{
                return nums[mid];
            }
        }
        return nums[l];
    }
};