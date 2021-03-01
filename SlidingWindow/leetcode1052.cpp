//
// Created by zhouhan on 2021/2/23.
//
#include "../common.h"
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        if(customers.empty()){
            return 0;
        }
        int n = customers.size();
        // 0到i中，得罪的客人数
        vector<int> v(n, 0);
        v[0] = grumpy[0] == 1? customers[0] : 0;
        int total = grumpy[0] == 1 ? 0 : customers[0];
        for(int i = 1; i < n ; i++){
            // 当前得罪了人
            if(grumpy[i] == 1){
                v[i] = v[i - 1] + customers[i];
            }else{
                total += customers[i];
                v[i] = v[i - 1];
            }
        }
        int maxVal = 0;
        for(int i = X - 1; i < n; i++){
            maxVal = max(maxVal, i - X >= 0 ? v[i] - v[i - X] : v[i]);
        }
        return total + maxVal;
    }
};