//
// Created by zhouhan on 2021/3/2.
//

// 我的解法
#include "../common.h"
class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        v = vector<vector<int>>(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sumVal = matrix[i][j];
                if(i - 1 >= 0 && j - 1 >= 0){
                    sumVal += v[i - 1][j - 1];
                }
                for(int k = 0; k <= i - 1; k++){
                    sumVal += matrix[k][j];
                }
                for(int k = 0; k <= j - 1; k++){
                    sumVal += matrix[i][k];
                }
                v[i][j] = sumVal;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        return v[row2][col2]
            - (col1 - 1 >= 0 ? v[row2][col1 - 1] : 0)
            - (row1 - 1 >= 0 ? v[row1 - 1][col2] : 0)
            // 有右上角
            + (row1 - 1 >= 0 && col1 - 1 >= 0? v[row1 - 1][col1 - 1] : 0);
    }
};

// 其他题解
//  前缀和空出第一行
class NumMatrix2 {
public:
    vector<vector<int>> v;
    NumMatrix2(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        v = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                v[i + 1][j + 1] = v[i][j+1] + v[i + 1][j] - v[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return v[row2 + 1][col2 + 1]
            - v[row1][col2 + 1]
            - v[row2 + 1][col1]
            + v[row1][col1];
    }
};