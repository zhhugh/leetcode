//
// Created by zhouhan on 2021/1/22.
//
#include "../common.h"

// 解法1：我自己的解法
// 数组的最后一个数字作为搜索二叉树的根 记为target
// [l...r - 1] 中找出最后一个小于target的元素下标，这是左右子树的分界线
// 判断[M + 1, r - 1]的元素是不是都比target的小， 如果有一个不小于target， 那么返回false
// 如果上面都没有返回false， 那么：
// 递归判断 [l..M] 和 [M + 1, r - 1]是否为搜索二叉树
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return _verifyPostorder(postorder, 0, postorder.size() - 1);
    }
    // [l, r]
    bool _verifyPostorder(vector<int> &postorder, int l, int r){
        if(l >= r) return true;
        int target = postorder[r];
        int M = l - 1;
        // 找到最后一个小于target的元素的下标 M
        for(int i = 0; i < r; i++){
            if(postorder[i] < target){
                M = i;
            }else if(postorder[i] == target){
                return false;
            }else{
                break;
            }
        }
        // 判断 M+1到r-1是否都大于target
        for(int i = M + 1; i < r; i++){
            if(postorder[i] <= target){
                return false;
            }
        }
        // 判断左右子树是否都为搜索二叉树
        return _verifyPostorder(postorder, l, M) && _verifyPostorder(postorder, M + 1, r - 1);
    }
};