//
// Created by zhouhan on 2021/2/14.
//

#include "../common.h"
class Solution {
    int n;
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        dfs("", n, n);
        return ans;
    }
    // right：左括号剩余数量
    // left： 右括号剩余数量
    void dfs(string s, int left, int right){
        if(s.size() == 2 * n){
            ans.push_back(s);
            return;
        }
        if(left > 0){
            dfs(s + "(", left - 1, right);
        }
        if(right > left){
            dfs(s + ")", left, right - 1);
        }
    }
};