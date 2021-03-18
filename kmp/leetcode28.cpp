//
// Created by zhouhan on 2021/3/2.
//

#include "../common.h"
class Solution {
public:
    int strStr(string haystack, string needle) {

        if(needle.empty()){
            return 0;
        }
        if(haystack.size() < needle.size()){
            return -1;
        }
        // 保证needle有一个元素
        vector<int> next = getNext(needle);
        int n = haystack.size();
        int m = needle.size();
        int j = 0;
        int i = 0;
        while (i < n && j < m) {
            if (haystack[i] == needle[j]) {
                j++;
                i++;
            } else if (next[j] != -1) {
                j = next[j];
            } else {
                i++;
            }
        }
        return j == m ? i - m : -1;
    }




    vector<int> getNext(string needle){
        int n = needle.size();
        if(n == 1){
            return {-1};
        }
        vector<int> next(n + 1, 0);
        next[0] = -1;
        next[1] = 0;
        int cur = 2;
        // cn: next[i - 1], 也是要和 i位置字符比较的字符的下标
        // 如果 match[cn] != match[i]， 则 cn = next[cn]
        int cn = 0;
        while(cur < n){
            if(needle[cur - 1] == needle[cn]){
                next[cur++] = ++cn;
            }else if(cn > 0){ //cn == 0 next[cn] = -1
                cn = next[cn];
            }else{ // cn = 0
                next[cur++] = 0;
            }
        }
        return next;
    }
};