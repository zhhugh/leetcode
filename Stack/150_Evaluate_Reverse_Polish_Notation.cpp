//
// Created by zhouhan on 2021/3/20.
//
#include "../common.h"
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            if(!isdigit(tokens[i][0]) && tokens[i].size() == 1){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                if(tokens[i] == "+"){
                    stk.push(b + a);
                }else if(tokens[i] == "-"){
                    stk.push(b - a);
                }else if(tokens[i] == "*"){
                    stk.push(b * a);
                }else{
                    stk.push(b / a);
                }
            }else{
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};