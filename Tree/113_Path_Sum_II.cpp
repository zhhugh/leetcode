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
    vector<int> path;
    int sum = 0;
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode *root, int targetSum){
        if(root == nullptr){
            return;
        }
        sum += root->val;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(targetSum == sum){
                res.push_back(path);
            }
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        sum -= root->val;
        path.pop_back();
    }
};
