//
// Created by zhouhan on 2021/3/2.
//
#include "../common.h"
class Solution {
public:
    int strStr(string haystack, string needle) {

    }

    vector<int> getNext(string needle){
        int n = needle.size();
        vector<int> next(n + 1, 0);
        next[0] = -1;
        next[1] = 0;
        int cur = 2;
        int cn = 0;
        while(cur < n){
            while(true){
                if(needle[cur - 1] == needle[cn]){
                    next[cur] = next[cn] + 1;
                    break;
                }else if(cn == -1){
                    next[cn] = 0;
                    break;
                }else{
                    cn = next[cn];
                }
            }
            cur++;
        }
    }
};