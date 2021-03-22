//
// Created by zhouhan on 2021/3/21.
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
    string path;
    int idx = 0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        _serialize(root);
        return path;
    }

    void _serialize(TreeNode *root){
        if(root == nullptr){
            path += "#_";
            return;
        }
        path += to_string(root->val);
        path += "_";
        _serialize(root->left);
        _serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(idx == path.size()){
            return nullptr;
        }
        if(data[idx] == '#'){
            idx +=2;
            return nullptr;
        }
        int i;
        for(i = idx; data[i] != '_'; i++);
        auto *root = new TreeNode(stoi(data.substr(idx, i - idx)));
        idx = i + 1;
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));