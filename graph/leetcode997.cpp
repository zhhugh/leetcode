//
// Created by zhouhan on 2021/3/6.
//


#include "../common.h"
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in(N + 1, 0);
        vector<int> out(N + 1, 0);
        for(auto i: trust){
            in[i[1]]++;
            out[i[0]]++;
        }
        for(int i = 1; i <= N; i++){
            if(in[i] == N - 1 && out[i] == 0){
                return i;
            }
        }
        return -1;
    }
};