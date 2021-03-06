//
// Created by zhouhan on 2021/3/21.
//

#include "../common.h"
class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool r = false;
        bool c = false;
        for(int i = 0; i < m; i++){
            if(!matrix[i][0]){
                r = true;
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(!matrix[0][j]){
                c = true;
                break;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1;j < n; j++){
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
        }

        if(c){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
        if(r){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }

};
