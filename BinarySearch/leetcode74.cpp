//
// Created by zhouhan on 2021/1/16.
//
#include "../common.h"

// 解法1 将该矩阵看成是一个长的数组，每个数组的元素下表可以通过行号和列号计算
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


// 解法2：找一个分界点 是行的最大值 列的最小值
// 根据这个分界点与target的大小关系，即可判断当前行和当前列是不是无效的
// 如果mat[x][y] < target, 说明当前行是无效的
// 如果mat[x][y] > target, 说明当前列是无效的
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while(x <= m - 1 && y >= 0){
            if(matrix[x][y] == target){
                return true;
            }else if(target > matrix[x][y]){
                ++x;
            }else if(target < matrix[x][y]){
                --y;
            }
        }
        return false;
    }
};