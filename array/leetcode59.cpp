//
// Created by zhouhan on 2021/3/16.
//
#include "../common.h"
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int s = 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                res[top][i] = s++;
            }
            top++;
            for(int i = top; i <= bottom; i++){
                res[i][right] = s++;
            }
            right--;
            for(int i = right; i >= left && top <= bottom; i--){
                res[bottom][i] = s++;
            }
            bottom--;
            for(int i = bottom; i >= top && left <= right; i--){
                res[i][left] = s++;
            }
            left++;
        }
        return res;
    }
};