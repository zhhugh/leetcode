//
// Created by zhouhan on 2021/2/14.
//
#include "../common.h"
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            vector<int> ans;
            dfs(nums, 0, n - 1, i, ans);
        }
        return res;
    }
    // [l...r] 选 len个数加入到ans中
    void dfs(vector<int> nums, int l, int r, int len, vector<int> ans){
        if(len == 0){
            res.push_back(ans);
            return;
        }
        if(l > r){
            return;
        }
        // 不选择当前数
        dfs(nums, l + 1, r, len, ans);
        // 选择当前数
        ans.push_back(nums[l]);
        dfs(nums, l + 1, r, len - 1, ans);
    }
};

class Solution2 {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back(vector<int>{});
        int n = nums.size();
        for(int i = 0; i < n; i++){
            vector<vector<int>> t = ans;
            for(auto item: t){
                item.push_back(nums[i]);
                ans.push_back(item);
            }
        }
        return ans;
    }
};

class Solution3 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int len = 1 << n;
        vector<vector<int>> res;
        for(int i = 0; i < len; i++){
            vector<int> tmp;
            for(int j = 0; j < n; j++){
                if(((i >> j) & 1) == 1){
                    tmp.push_back(nums[j]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};