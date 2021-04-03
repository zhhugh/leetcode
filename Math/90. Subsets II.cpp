//
// Created by zhouhan on 2021/3/31.
//
#include <istream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()){
            return {{}};
        }
        int n = nums.size();
        int idx = -1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int preIdx = 0;
        int curIdx = -1;
        for(int i = 0; i < n; i++){
            curIdx = res.size(); // 梦开始的地方
            if(i > 0 && nums[i] == nums[i - 1]){
                int len = res.size();
                for(int j = len - 1; j >= preIdx; j--){ // 结束于梦开始的地方
                    vector<int> tmp = res[j];
                    tmp.push_back(nums[i]);
                    res.push_back(tmp);
                }
            }else{
                int len = res.size();
                for(int j = 0; j < len; j++){
                    vector<int> tmp = res[j];
                    tmp.push_back(nums[i]);
                    res.push_back(tmp);
                }
            }
            preIdx = curIdx;
        }
        return res;
    }
};