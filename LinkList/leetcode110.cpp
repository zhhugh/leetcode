//
// Created by zhouhan on 2021/2/9.
//
#include "../common.h"

// 自顶向下调用
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return isBalanced(root->left) && isBalanced(root->right) && abs(getHeight(root->left) - getHeight(root->right)) <= 1;
    }

    int getHeight(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};


class Solution2 {
public:

    bool isBalanced(TreeNode* root) {
        return isBalancedAndHeight(root) != -1;
    }

    int isBalancedAndHeight(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        int leftHeight = isBalancedAndHeight(root->left);
        int rightHeight  = isBalancedAndHeight(root->right);
        if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1){
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }
};