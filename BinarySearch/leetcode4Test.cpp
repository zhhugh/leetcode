//
// Created by zhouhan on 2021/3/19.
//
#include "../common.h"
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()){
            vector<int> tmp = nums2;
            nums2 = nums1;
            nums1 = tmp;
        }
        int len1 = nums1.size();
        int len2 = nums2.size();
        int left = 0;
        int right = len1;
        int totalleft = (len1 + len2 + 1) / 2;
        while(left < right){
            int mid = left + (right - left + 1) / 2;
            int j = totalleft - mid;
            if(nums1[mid - 1] > nums2[j]){
                right = mid - 1;
            }else{
                left = mid;
            }
        }
        int j = totalleft - left;
        int leftMax1 = left == 0 ? INT_MIN: nums1[left - 1];
        int leftMax2 = j == 0 ? INT_MIN: nums2[j - 1];
        int rightMin1 = left == len1 ? INT_MAX : nums1[left];
        int rightMin2 = j == len2 ? INT_MAX : nums2[j];
        if((len1 + len2) % 2 == 1){
            return max(leftMax1, leftMax2);
        }else{
            return (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2.0;
        }
    }
};