//
// Created by zhouhan on 2021/2/14.
//
#include "../common.h"
class Solution {
public:
    int n;
    vector<string> res;
    vector<string> permutation(string S) {
        this->n = S.size();
        dfs(S, 0);
        return res;
    }

    void dfs(string s, int idx){
        if(idx == n){
            res.push_back(s);
            return;
        }
        // 选一个数和当前位置交换
        for(int j = idx; j < n; j++){
            swap(s[idx], s[j]);
            dfs(s, idx + 1);
            swap(s[idx], s[j]);
        }
    }
};
