//
// Created by zhouhan on 2021/2/21.
//
#include "../common.h"
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans;
        vector<int> v(n, 0);
        vector<int> u(n, 0);
        vector<int> sum1(n, 0);
        vector<int> sum2(n, 0);
        for(int i = 1; i < n; i++){
            sum1[i] = sum1[i - 1] + (boxes[i - 1] - '0');
        }
        for(int i = n - 2; i >= 0; i--){
            sum2[i] = sum2[i + 1] + (boxes[i + 1] - '0');
        }
        // i左边跳到i
        for(int i = 1; i < n; i++){
            v[i] += v[i - 1] + sum1[i];
        }
        // i右边跳到i
        for(int i = n - 2; i >= 0; i--){
            u[i] = u[i + 1] + sum2[i];
        }
        for(int i = 0; i < n; i++){
            ans.push_back(v[i] + u[i]);
        }
        return ans;
    }
};