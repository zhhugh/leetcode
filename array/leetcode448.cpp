//
// Created by zhouhan on 2021/2/13.
//

#include "../common.h"
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= n; i++){
            if(cur >= n || i != nums[cur]){
                ans.push_back(i);
            }else{
                cur++;
                while(cur < n - 1 && nums[cur] == nums[cur - 1]) {
                    cur++;
                }
            }
        }
        return ans;
    }
};

// 数组的原地修改
// 知道数的范围，用范围外的数字标记是否访问
// 原数组的下标表示哈希表中的key（或者经过某种变换得到key）
// 原数组中值会经过特殊处理变成范围外的数字
// 通过某种运算可以把范围外的数字变成原数字，再去标记

class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(auto num: nums){
            // 下标范围是0～n-1，所以减1， 取余是因为该数可能被之前的数改变过
            // 取余能去掉前面的数给当前数加的n
            int x = (num - 1) % n;
            nums[x] += n;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] <= n){
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};