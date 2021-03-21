//
// Created by zhouhan on 2021/3/20.
//

#include<iostream>
#include<vector>
using namespace std;

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
    int ans = 0;
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return 0;
        }
        dfs(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return ans;
    }
    void dfs(TreeNode *root, int sum){
        if(root == nullptr){
            return;
        }
        if(root->val == sum){
            ans ++;
        }
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
};