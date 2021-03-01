//
// Created by zhouhan on 2021/2/21.
//

#include "../common.h"
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int l1 = 0, l2 = 0;
        int n = word1.size();
        int m = word2.size();
        while(l1 < n || l2 < m){
            if(l1 < n){
                ans += word1[l1++];
            }
            if(l2 < m){
                ans += word2[l2++];
            }
        }
        return ans;
    }
};