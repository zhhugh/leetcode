//
// Created by zhouhan on 2021/1/20.
//
#include "../common.h"


// 方法一：拓展中心法
//（1） 从倒数第二个元素开始，以该元素为中心，向左向右扩展
// 遍历完第二个数停止，因为首尾元素扩散最多长度为1
// (2)  在以元素为中心的时候，顺便以该元素右边的空隙为中心向左向右扩展
// 因为遍历元素的时候， 只遍历到第二个元素， 而第一个元素右边的空隙没有扩展，所以最后要单独考虑

class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;// 因为后面要单独计算以第一个间隙为中心的回文串的长度，所以元素数量必须大于两个
        int maxLen = 1; // 最大长度
        int start = 0; // 最大字符串的开始位置
        for(int cur = n - 2; cur > 0; cur--){
            int l = cur - 1, r = cur + 1;// 回文串
            int curLen = 1;
            // 以字符为中心， 向左向右扩展
            while(l >= 0 && r <= n - 1 && s[l] == s[r]){
                curLen += 2;
                l--, r++;
            }
            if(curLen > maxLen){
                maxLen = curLen;
                start = l + 1;
            }
            curLen = 0;
            l = cur, r = cur + 1;
            // 以字符间隙为中心，向左向右扩展， 左边界 + 右边界 = 2 *cur + 1
            while(l >= 0 && r <= n - 1 && s[l] == s[r]){
                curLen += 2;
                l--, r++;
            }
            if(curLen > maxLen){
                maxLen = curLen;
                start = l + 1;
            }

        }
        // 处理最后一个空隙（只有数组元素大于等于两个时， 才有最后一个空隙）
        if(s[0] == s[1] && maxLen < 2){
            maxLen = 2;
            start = 0;
        }
        return s.substr(start, maxLen);
    }
};

// 解法二： 马拉车算法
// (1) 预处理 每个字符两边都加上'#'， 首尾加上特殊字符 '^', '$'
// (2) 变量定义：c是已经遍历的字符中的对称中心， r是对称半径
//

class Solution2 {
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
            int li = 2 * c - i;
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