//
// Created by zhouhan on 2021/3/11.
//
#include "../common.h"
class Solution {
public:
    int calculate(string s) {
        vector<string> str = prePrecess(s);
        stack<string> stk;
        bool flag = false;
        for(auto & i : str){
            if(!flag){
                stk.push(i);
                if(i == "*" || i == "/"){
                    flag = true;
                }
            }else{
                int x = stoi(i);
                string sym = stk.top();
                stk.pop();
                int y = stoi(stk.top());
                stk.pop();
                if(sym == "*"){
                    stk.push(to_string(x * y));
                }else{
                    stk.push(to_string(y / x));
                }
                flag = false;
            }
        }
        stack<string> t;
        while(!stk.empty()){
            t.push(stk.top());
            stk.pop();
        }
        int res = 0;
        bool add = true;
        while(!t.empty()){
            string popS = t.top();
            t.pop();
            if(popS == "+" || popS == "-"){
                add = (popS == "+" )|| (!add);
            }else if(add){
                res += stoi(popS);
                add = true;
            }else{
                res -= stoi(popS);
                add = true;
            }
        }
        return res;
    }



    vector<string> prePrecess(string s){
        vector<string> res;
        int n = s.size();
        int i = 0;
        string t;
        while(i < n){
            if(s[i] == ' '){
                i++;
            }else if(isdigit(s[i])){
                t += s[i++];
                if(i == n || !isdigit(s[i])){
                    res.push_back(t);
                    t = "";
                }
            }else{
                string tmp;
                res.push_back(tmp + s[i++]);
            }
        }
        return res;
    }
};
