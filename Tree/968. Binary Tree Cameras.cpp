//
// Created by zhouhan on 2021/3/23.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "../common.h"
struct status{
    int a, b, c;
};
class Solution {
public:

    int minCameraCover(TreeNode* root) {
        return dp(root).b;
    }
    status dp(TreeNode *root) {
        if(root == nullptr){
            return {INT_MAX / 2, 0, 0};
        }
        status left = dp(root->left);
        status right  = dp(root->right);
        int a = left.c + right.c + 1;
        int b = min(a, min(left.a + right.b, right.a + left.b));
        int c = min(a, left.b + right.b);
        return {a, b, c};
    }
};




class Solution2 {
public:
    struct status{
        int a; // 覆盖两棵子数需要的结点数
        int b; // 根结点安装摄像头的情况下， 覆盖整棵树需要的结点数
        int c; // 无论根结点情况如何， 覆盖整棵树需要的结点数
        status(int a, int b, int c) : a(a), b(b), c(c) {}
    };
    int minCameraCover(TreeNode* root) {
        return dp(root).c;
    }

    status dp(TreeNode *root){
        if(root == nullptr){
            return {0, INT_MAX / 2, 0};
        }
        auto left = dp(root->left);
        auto right = dp(root->right);
        int b = left.a + right.a + 1;
        int a = min(left.c + right.c, b);
        int c = min(b, min(left.b + right.c, right.b + left.c));
        status cur(a, b, c);
        return cur;
    }
};