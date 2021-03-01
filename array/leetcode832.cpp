//
// Created by zhouhan on 2021/2/24.
//
#include "../common.h"
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        for(auto &arr: A){
            int l = 0, r = n - 1;
            while(l < r){
                if(arr[l] == arr[r]){
                    arr[l] = !arr[l];
                    arr[r] = !arr[r];
                }
                l++;
                r--;
            }
            if(n % 2 == 1){
                arr[l] = !arr[l];
            }
        }
        return A;
    }
};