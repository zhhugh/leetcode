//
// Created by zhouhan on 2021/4/1.
//

#include <iostream>
class Solution {
public:
    int clumsy(int N) {
        int res = 0;
        for(int i = N; i >= 1; i -= 4){
            int cur;
            if(i >= 4){
                if(i == N){
                    cur = i * (i - 1) / (i - 2) + (i - 3);
                    res += cur;
                }else{
                    cur = i * (i - 1) / (i - 2) - (i - 3);
                    res -= cur;
                }
            }else{
                if(i == 3){
                    cur = i * (i - 1) / (i - 2);
                }else if(i == 2){
                    cur = i * (i - 1);
                }else{
                    cur = i;
                }
                if(i == N){
                    res += cur;
                }else{
                    res -= cur;
                }
            }
        }
        return res;
    }
};