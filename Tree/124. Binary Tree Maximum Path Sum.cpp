//
// Created by zhouhan on 2021/3/22.
//


#include "../common.h"
class Solution {
public:
    int maxVal = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        dfs(root);
        return maxVal;
    }

    int dfs(TreeNode *cur){
        if(cur == nullptr){
            return 0;
        }
        int left = dfs(cur->left);
        int right = dfs(cur->right);
        int curVal = max(cur->val, cur->val + max(left, right));
        maxVal = max(curVal, max(maxVal, cur->val + left + right));
        return curVal;
    }
};