//
// Created by zhouhan on 2021/3/9.
//
#include "../common.h"

class Solution {
public:
    string removeDuplicates(string S) {
        int idx = -1;
        int n = S.size();
        for(int i = 0; i < n; i++){
            if(idx == -1 || S[i] != S[idx]){
                S[++idx] = S[i];
            }else{
                idx--;
            }
        }
        return S.substr(0, idx + 1);
    }
};