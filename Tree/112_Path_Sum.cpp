//
// Created by zhouhan on 2021/3/20.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        // 叶子结点的时候判断
        if(root->left == nullptr && root->right == nullptr && targetSum == root->val){
            return true;
        }
        return hasPathSum(root->left, targetSum - root->val)
             || hasPathSum(root->right, targetSum - root->val);
    }
};