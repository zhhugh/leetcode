//
// Created by zhouhan on 2021/3/15.
//
#include "../common.h"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            for(int i = right; i >= left && top <= bottom; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i = bottom; i >= top && left <= right; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};