//
// Created by zhouhan on 2021/2/12.
//
// 计算杨辉三角第k行
#include "../common.h"

// 方法一是我第一个想法，滚动数组，很容易就ac了
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur;
        vector<int> pre;
        for(int k = 0; k <= rowIndex; k++){
            // 第0层直接填
            if(k == 0){
                cur.push_back(1);
            }else{
                for(int i = 0; i < k; i++){
                    if(i == 0 || i == k - 1){
                        cur.push_back(1);
                    }else{
                        cur.push_back(pre[i - 1] + pre[i]);
                    }
                }
            }
            pre = cur;
            cur = vector<int>{};
        }
        return pre;
    }
};

// 方法二是利用组合数后一项与前一项的关系，直接递推
class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex, 0);
        ans[0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            ans[i] = ans[i - 1] * ((rowIndex - i + 1) / i);
        }
        return ans;
    }
};

// 方法3是利用组合数的性质，从后往前计算
class Solution3 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        ans[0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            for(int j = i; j > 0; j++){
                ans[j] += ans[j - 1];
            }
        }
        return ans;
    }
};