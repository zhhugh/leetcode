//
// Created by zhouhan on 2021/3/22.
//
#include "../common.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int idx = 0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "#_";
        }
        return to_string(root->val) + "_"
            + serialize(root->left)
            + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[idx] == '#'){
            idx += 2;
            return nullptr;
        }
        int i;
        int num = 0;
        for(i = idx; data[i] != '_'; i++){
            num = num * 10 + data[i] - '0';
        }
        auto *root = new TreeNode(num);
        idx = i + 1;
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;