//
// Created by zhouhan on 2021/3/1.
//
#include "../common.h"
// 自己实现的算法
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>{1});
        for(int i = 1; i < numRows; i++){
            int len = ans.back().size() + 1;
            vector<int> tmp = ans.back();
            vector<int> row(len, 1);
            for(int j = 1; j < len - 1; j++){
                row[j] = tmp[j] + tmp[j - 1];
            }
            ans.push_back(row);
        }
        return ans;
    }
};

// 官方题解

class Solution2 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i < numRows; i++){
            ans[i].resize(i + 1);
            ans[i][0] = 1;
            ans[i][i] = 1;
            for(int j = 1; j < i; j++){
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};