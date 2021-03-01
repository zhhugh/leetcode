//
// Created by zhouhan on 2021/2/22.
//

#include "../common.h"
class Solution {
public:
    string intToRoman(int num) {
        vector<string> mp[4]{
                {"", "I", "II", "III","IV", "V", "VI", "VII","VIII", "IX"},
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                {"", "C", "CC", "CCC", "CD", "D" , "DC", "DCC", "DCCC", "CM"},
                {"", "M", "MM", "MMM"}
        };
        string tmp;
        tmp += mp[3][num / 1000 % 10];
        tmp += mp[2][num / 100 % 10];
        tmp += mp[1][num / 10 % 10];
        tmp += mp[0][num % 10];
        return tmp;
    }
};