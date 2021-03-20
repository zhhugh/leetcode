//
// Created by zhouhan on 2021/3/16.
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

// Morris 遍历
// Morris 序

class Morris {
public:
    void inorderTraversal(TreeNode* root) {
        TreeNode *cur = root;
        TreeNode *mostRight;
        while(cur != nullptr){
            // 左子树最右边结点
            mostRight = cur->left;
            // 如果有左子树
            if(mostRight != nullptr){
                // 找到左子树最右结点
                while(mostRight->right != nullptr && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                // 第一次来到cur结点
                if(mostRight->right == nullptr){
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                }else{// 第二次来到cur结点
                    mostRight->right = nullptr;
                }
            }
            // 没有左子树， 或者左子树的最右边结点指向cur
            cur = cur->right;
        }
    }
};



class MorrisInorder {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *cur = root;
        TreeNode *mostRight;
        vector<int> ans;
        while(cur != nullptr){
            mostRight = cur->left;
            if(mostRight != nullptr){
                while(mostRight->right != nullptr && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == nullptr){
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                }else{
                    mostRight->right = nullptr;
                    ans.push_back(cur->val);
                }
            }else{
                ans.push_back(cur->val);
            }
            cur = cur->right;
        }
        return ans;
    }
};
        }
        return ans;
    }
};

