//
// Created by zhouhan on 2021/2/14.
//
#include "../../common.h"

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        char start = '0';
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0 && s[i] != start){
                ans1 += 1;
            }else if(i % 2 == 1 && s[i] == start){
                ans1 += 1;
            }
        }
        start = '1';
        for(int i = 0; i < n; i++){
            if(i % 2 == 0 && s[i] != start){
                ans2 += 1;
            }else if(i % 2 == 1 && s[i] == start){
                ans2 += 1;
            }
        }
        return min(ans1, ans2);
    }
};