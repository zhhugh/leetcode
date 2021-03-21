//
// Created by zhouhan on 2021/3/20.
//
#include <string>
#include <iostream>
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
    string path;
    int sumNumbers(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
    }

    void dfs(TreeNode *root){
        if(root == nullptr){
            return;
        }
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){

        }
    }

};