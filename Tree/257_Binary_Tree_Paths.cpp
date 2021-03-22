//
// Created by zhouhan on 2021/3/21.
//
#include <iostream>
#include <vector>
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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode *cur){
        if(cur == nullptr){
            return;
        }
        string prePath = path;
        path += to_string(cur->val);
        if(cur->left == nullptr && cur->right == nullptr){
            res.push_back(path);
        }
        path += "->";
        dfs(cur->left);
        dfs(cur->right);
        path = prePath;
    }
};