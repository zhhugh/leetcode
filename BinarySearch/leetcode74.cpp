//
// Created by zhouhan on 2021/1/16.
//
#include "../common.h"


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = n * m - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            // 序号和行号可以互相转化
            int row = mid / n;
            int col = mid % n;
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return false;
    }
};