//
// Created by zhouhan on 2021/2/16.
//
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct info{
        TreeNode *begin;
        TreeNode *end;

        info(TreeNode *begin, TreeNode *anEnd) : begin(begin), end(anEnd) {}
    };
    TreeNode* convertBiNode(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        return _sub(root)->begin;
    }

    info * _sub(TreeNode *root){
        if(root == nullptr){
            return nullptr;
        }
        info *left = _sub(root->left);
        info *right = _sub(root->right);
        TreeNode *newhead = nullptr;
        TreeNode *newtail = nullptr;
        root->left = nullptr;
        if(left != nullptr){
            left->end->right = root;
            newhead = left->begin;
        }else{
            newhead = root;
        }
        if(right != nullptr){
            root->right = right->begin;
            newtail = right->end;
        }else{
            root->right = nullptr;
            newtail = root;
        }
        return new info(newhead, newtail);
    }

};

class Solution2 {
public:
    TreeNode *prev = nullptr;
    TreeNode *newHead = nullptr;
    TreeNode* convertBiNode(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        return _sub(root);

    }

    TreeNode * _sub(TreeNode * root){
        if(root == nullptr){
            return nullptr;
        }
        _sub(root->left);
        if(prev == nullptr){
            prev = root;
            newHead = root;
        }else{
            prev->right = root;
        }
        root->left = nullptr;
        prev = root;
        _sub(root->right);
        return newHead;
    }
};