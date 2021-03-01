//
// Created by zhouhan on 2021/2/25.
//
#include "../common.h"
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
     int m = matrix[0].size();
     int n = matrix.size();
     vector<vector<int>>res (m, vector<int>(n, 0));
     if(m == n){
     for(int i = 0; i < n; i++){
         for(int j = i; j < n; j++){
             res[i][j] = matrix[j][i];
             res[j][i] = matrix[i][j];
         }
     }
     }else{
         for(int i = 0; i < n; i++){
             for(int j = 0; j < m; j++){
                 res[j][i] = matrix[i][j];
             }
         }
     }
     return res;
    }
};
