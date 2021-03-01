//
// Created by zhouhan on 2021/2/21.
//

#include "../common.h"
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int maxval = 0;
        while(l < r){
            if(height[l] < height[r]){
                maxval = max(maxval, height[l] * (r - l));
                l++;
            }else{
                maxval = max(maxval, height[r] * (r - l));
                r--;
            }
        }
        return maxval;

    }
};