//
// Created by zhouhan on 2021/1/16.
//

#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * 马拉车计算最长回文子串
 */
class Manacher {
public:

    string preProcess(string s){
        string t = "^#";
        for(auto c: s){
            t += c;
            t += "#";
        }
        t += "$";
        return t;
    }

    string longestPalindrome(string s) {
        string newS = preProcess(s);
        int maxlen = 0, idx = 0;
        // 当i = 1是， "^#", 显然r = 1, c = 1
        int c = 1, r = 1;
        int len  = newS.size();
        int m[len];
        fill(m, m + len, 0);
        for(int i = 2; i < len; i++){
            int li = 2 * c - i; // 找对称点
            if(i + m[li] < r){
                m[i] = m[li];
            }else{
                //
                // 如果r - i == -1的话， m[i] == - 1, 但是在后面的while循环中会加回到0
                // 如果 r <= i, 那么这个m[i]是当前的最大值， 后面要在此基础上扩展
                m[i] = r - i;
            }
            // mi[i] 为负数， 经过下面这个循环可以m[i] 加到0
            while(newS[i - m[i] - 1] == newS[i + m[i] + 1]){
                m[i]++;
            }
            // 扩展后
            if(i + m[i] > r){
                r = i + m[i];
                c = i;
            }
            if(m[i] > maxlen){
                maxlen = m[i];
                idx = i;
            }
        }

        // 对于非特殊字符，索引为i 要映射到原来字符串，为（i - 2）/ 2
        // 原因是要先减去前面两个字符'^', '#', 每次都是两个字符两个字符的增加，所以除2
        // idx是我们找到的最长回文子串的扩展中心
        // idx - maxlen 是找到最长子串的第一个字符的左边特殊字符'#'的索引
        // 因为如果以idx为中心扩展能到非特殊字符，那么一定能再多扩展一位到特殊字符'#'
        // 原因是每个字符左右都有一个'#'
        // 对于这个特殊字符， 代表的是它右边的第一个字符为开头的子串
        // idx - maxlen = i - 1 (i表示特殊字符右边的第一个字符的索引）
        // （idx - maxlen） / 2 == （i - 1）/ 2 == （i - 2）/ 2（因为是向下取整）
        // 这样就映射到了原来字符串的索引
        // 所以 begin = （idx - maxlen) >> 1
        int begin  = (idx - maxlen) >> 1;
        return s.substr(begin, maxlen);
    }
};


#endif //LEETCODE_COMMON_H
