//
// Created by zhouhan on 2021/3/24.
//
#include "../common.h"
class Solution {
public:
    struct status{
        int child;
        int robOrNot;
    };
    int rob(TreeNode* root) {
        return dp(root).robOrNot;
    }

    status dp(TreeNode *root){
        if(root == nullptr){
            return {0, 0};
        }
        auto left = dp(root->left);
        auto right = dp(root->right);
        int child = left.robOrNot + right.robOrNot; // 从孩子中获利的最大值
        int robOrNot = max(root->val + left.child + right.child, child); // 当前获得最大值
        return {child, robOrNot};
    }
};