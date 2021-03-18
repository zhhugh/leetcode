//
// Created by zhouhan on 2021/3/15.
//
#include "../common.h"
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minVal = INT_MAX;
        int ans = -1;
        int a  = -1;
        int b = -1;
        int c = -1;
        for(int i = 0; i < n; i++){
            a = nums[i];
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                b = nums[l];
                c = nums[r];
                int curVal = a + b + c - target;
                if(curVal > 0){
                    if(curVal < minVal){
                        minVal = curVal;
                        ans = a + b + c;
                    }
                    r--;
                }else if(a + b + c -target < 0){
                    if(- curVal < minVal){
                        minVal = - curVal;
                        ans = a + b + c;
                    }
                    l++;
                }else{
                    return target;
                }
            }
        }
        return ans;
    }
};