//
// Created by zhouhan on 2021/2/17.
//

// 数字是第几个 变换为二维数组中的位置
// row = x / c
// col = x % c
#include "../common.h"
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if(m * n != r * c){
            return nums;
        }
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for(int i = 0; i < m * n; i++){
            ans[i / c][i % c] = nums[i / m][i % m];
        }
        return ans;
    }
};