//
// Created by zhouhan on 2021/2/17.
//

#include "../common.h"

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int odd = 0;
        int even = 0;
        for(int i = 0; i < n; i ++){
            if((position[i] & 1) == 0){
                even ++;
            }else{
                odd ++;
            }
        }
        return min(odd, even);
    }
};
