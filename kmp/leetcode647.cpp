//
// Created by zhouhan on 2021/3/9.
//
#include "../common.h"
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()){
            return 0;
        }
        int n = s.size();
        string str = preProcess(s);
        vector<int> m(2 * n + 1, 0);
        int c = -1;
        int r = -1;
        int res = 0;
        for(int i = 0; i < m.size(); i++){
            m[i] = i < r ? min(r - i, m[2 * c - i]) : 1;
            while(i + m[i] < m.size() && i - m[i] >= 0){
                if(str[i + m[i]] == str[i - m[i]]){
                    m[i]++;
                }else{
                    break;
                }
            }
            if(i + m[i] > r){
                r = i + m[i];
                c = i;
            }
        }
        for(int i = 0; i < m.size(); i++){
            res += m[i] / 2;
        }
        return res;
    }

    string preProcess(string s){
        string t = "#";
        for(auto c: s){
            t += c;
            t += "#";
        }
        return t;
    }
};