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
class Solution {
public:
    map<int, int> dp;
    int maxTime = 0;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        dfs(root);
        for(auto x: dp){
            if(x.second == maxTime){
                ans.push_back(x.first);
            }
        }
        return ans;
    }

    int dfs(TreeNode *cur){
        if(cur == nullptr){
            return 0;
        }
        int left = dfs(cur->left);
        int right = dfs(cur->right);
        dp[cur->val + left + right]++;
        maxTime = max(dp[cur->val + left + right], maxTime);
        return left + right + cur->val;
    }
};