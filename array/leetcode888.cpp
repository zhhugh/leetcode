//
// Created by zhouhan on 2021/2/12.
//

#include "../common.h"
#include <unordered_map>
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        unordered_map<int, int>mp;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < n; i++){
            sum1 += A[i];
        }
        for(int i = 0; i < m; i++){
            sum2 += B[i];
        }
        int target = (sum1 - sum2) / 2;
        for(int i = 0; i < n; i++){
            mp[A[i] - target] = i;
        }
        for(int i = 0; i < m; i++){
            if(mp.find(B[i]) != mp.end()){
                return vector<int>{A[mp[B[i]]], B[i]};
            }
        }
        return vector<int>{};
    }
};