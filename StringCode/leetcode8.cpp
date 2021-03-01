//
// Created by zhouhan on 2021/2/17.
//


#include "../common.h"
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(s[i] == ' '){
            i++;
        }
        // i为第一个不为空格的字符
        int flag;
        if(s[i] == '+'){
            flag = 1;
        }else if(s[i] == '-'){
            flag = 2;
        }else{
            flag = 3;
        }
        int res = 0;
        int m = INT_MIN / 10;
        int o = INT_MIN % 10;
        // 如果是负数
        while((flag == 2) && i < n && s[i] >= '0' && s[i] <='9'){
            if(res < m || res == m && s[i] - '0' < o){
                return INT_MIN;
            }
            res = res * 10 + (s[i] - '0');
            i++;
        }
        // 如果是正数
        m = INT_MAX / 10;
        o = INT_MAX % 10;
        while((flag == 1 ||flag ==  3) && i < n && s[i] >= '0' && s[i] <= '9'){
            if(res > m || (res == m) && (s[i] - '0') > o){
                return INT_MAX;
            }
            res = res * 10 + (s[i] - '0');
            i++;
        }
        return (flag == 1 || flag == 3) ? res : -res;
    }
};