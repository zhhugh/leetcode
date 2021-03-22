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
    int path = 0; // 记录从根结点到当前结点的路径
    int ans = 0; // 记录所有从根结点到叶子结点的路径之和
    int sumNumbers(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *cur){
        if(cur == nullptr){
            return;
        }
        int sum = path;
        // 到达当前结点， 将当前结点添加到路径中
        path = path * 10 + cur->val;
        // 到达叶子结点， 则收集答案
        if(cur->left == nullptr && cur->right == nullptr){
            ans += path;
        }
        // 以当前结点为基准， 向左向右搜索
        dfs(cur->left);
        dfs(cur->right);
        // 当前结点为头的结果已经搜索完成
        // 开始返回到父函数
        // 父函数选择另外一条分支
        // 所以当前要恢复成父结点的现场
        // 即当前函数过后， 回到初始状态
        path = sum;
    }

};


class Solution2 {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode *cur, int preSum){
        if(cur == nullptr){
            return 0;
        }
        int sum = preSum * 10 + cur->val;
        if(cur->left == nullptr && cur->right == nullptr){
           return sum;
        }
        // 如果我不是叶子结点
        // 要解决这个问题
        // 等价于左右子左右子树去解决这个问题， 左右子树的累加和也发生变化
        return dfs(cur->left, sum) + dfs(cur->right, sum);
    }
};