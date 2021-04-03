//
// Created by zhouhan on 2021/3/21.
//
#include "../common.h"

class Codec {
public:
    string path;
    int idx = 0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        _serialize(root, "");
        return path;
    }

    void _serialize(TreeNode *root, string str){
        if(root == nullptr){
            str += "#";
            return;
        }
        str += to_string(root->val);
        str += '_';
        _serialize(root->left, str);
        _serialize(root->right, str);
    }


    TreeNode* deserialize(string data) {
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

