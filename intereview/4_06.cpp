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
        TreeNode *pre; // 是否有答案
        TreeNode *end; // 结束结点
        info(): pre(nullptr),end(nullptr){};
    };

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return _sub(root, p)->pre;
    }
    // 有答案，则存在pre中， 没答案则pre = nullptr；
    // 最后一个结点存在end中
    info *_sub(TreeNode *root, TreeNode *p){
        if(root == nullptr){
            return new info();
        }
        info *cur = new info();
        info *left = _sub(root->left, p);
        info *right = _sub(root->right, p);
        cur->end = right->end;
        if(root == p){
            cur->pre = getMostleft(root);
        }
        if(left->pre == nullptr && left->end == p){
            cur->pre = root;
        }
        // 与x无关
        if(left->pre != nullptr){
            cur->pre = left->pre;
        }
        if(right->pre != nullptr){
            cur->pre = right->pre;
        }
        return cur;
    }
    TreeNode *getMostleft(TreeNode *root){
        if(root == nullptr){
            return nullptr;
        }
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }
};