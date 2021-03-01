//
// Created by zhouhan on 2021/2/15.
//

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 如果不存在p且不存在q，则返回null
    // 如果存在p则返回p
    // 如果存在q则返回q
    // 如果都存在则有一边一定返回null
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return _sub(root, p, q);
    }
    TreeNode *_sub(TreeNode * root, TreeNode *p, TreeNode *q){
        if(root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode *left = _sub(root->left, p, q);
        TreeNode *right = _sub(root->right, p, q);
        if(left != nullptr && right != nullptr){
            return root;
        }
        return left == nullptr ? right : left;
    }
};