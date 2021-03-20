//
// Created by zhouhan on 2021/1/18.
//

// 在c++中，除法默认是向下取整
// 因此， （m + n) / 2 与 （m + n + 1） / 2 是相等的



#include "../common.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 保证nums1的长度小于等于nums2的长度
        // 这样nums2的长度总是会 >= 总长度的一半，这样就不会越界了
        //
        if(nums1.size() > nums2.size()){
            vector<int> tmp = nums2;
            nums2 = nums1;
            nums1 = tmp;
        }
        int len1 = nums1.size();
        int len2 = nums2.size();
        // 分割线左边的数量
        // 如果是偶数 则为（len1 + len2) / 2 == (len1 + len2 + 1) / 2
        // 如果是奇数 则为（len1 + len2 + 1） / 2
        // 所以综合起来 分割线左边的数量为 （len1 + len2 + 1) / 2
        int totalleft = (len1 + len2 + 1) / 2;
        int left = 0, right = len1; // i 的查找区间[0, len1], 表示i左边有多少个数
        while(left < right){
            int i = left + (right - left + 1) / 2; // right - left 代表right 到 left + 1有 多少个数
            int j = totalleft - i;// 第二个数组分割线的位置，也就是分割线右边第一个元素
            if(nums1[i - 1] > nums2[j]){// 第一个数组分割// 线左边的元素大于第二个数组分割线右边的元素
                right = i - 1;
            }else{ // nums1[i - 1] <= nums2[j]
                left = i; // [i, right]
            }
        }
        // 退出上面的循环， 则表示找到了分割线left
        int i = left;
        int j = totalleft - i;
        // 如果总数为奇数， 那么中位数就是分割线左边的最大值
        // 如果总数为偶数， 那么中位数就是分割线左边的最大值与分割线右边的最小值的平均数
        int nums1leftMax = i == 0? INT32_MIN:nums1[i - 1]; // 第一个数组分割线左边的第一个元素
        int nums1rightMin = i == len1? INT32_MAX : nums1[i];
        int nums2leftMax = j == 0 ? INT32_MIN : nums2[j - 1];
        int nums2rightMin = j == len2? INT32_MAX : nums2[j];
        if((len1 + len2) % 2 == 1){ // 奇数， 由于左边多一个数
            return (double)max(nums1leftMax, nums2leftMax);
        }else{
            return (max(nums1leftMax, nums2leftMax) + min(nums1rightMin, nums2rightMin)) / 2.0;
        }

    }
};



