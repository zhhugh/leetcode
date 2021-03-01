//
// Created by zhouhan on 2021/2/22.
//
#include "../common.h"
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp{
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        int n = s.size();
        int sumVal = 0;
        for(int i = 0; i < n - 1; i++){
            if(mp[s[i]] < mp[s[i + 1]]){
                sumVal -= mp[s[i]];
            }else{
                sumVal += mp[s[i]];
            }
        }
        sumVal += mp[s[n - 1]];
        return sumVal;
    }
};